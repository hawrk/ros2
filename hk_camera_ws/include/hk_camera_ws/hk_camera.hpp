/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-09 09:56:04
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-10 09:24:23
 * @FilePath: /hk_camera_ws/include/hk_camera_ws/fd_camera.hpp
 * @Description: 对海康工业相机SDK的C++封装 (v3.0)
 */

#include "rclcpp/rclcpp.hpp"

#include <opencv4/opencv2/opencv.hpp>

#include "hk_sdk/include/MvCameraControl.h"
#include "hk_sdk/include/MvErrorDefine.h"

#define MAX_IMAGE_DATA_SIZE (4 * 2048 * 3072)


class HKCamera {
public:
    HKCamera() = default;

    // wrapper hk sdk
    int initial_camera();

    int start_camera();
    // 停止取流
    int stop_camera();

    static void *work_thread(void* handle);
    

    ~HKCamera();

private:

    void *handle_;  // 设备句柄

    bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo);

};

int HKCamera::initial_camera() {
    int nRet = MV_OK;
    nRet = MV_CC_Initialize();
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_Initialize fail, code:[%d]", nRet);
        return nRet;
    }
    
    // 枚举设备
    MV_CC_DEVICE_INFO_LIST stDeviceList;
    memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
    nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_EnumDevices fail, code:[%d]", nRet);
        return nRet;
    }
    unsigned int nIndex = 0;
    if(stDeviceList.nDeviceNum > 0) {
        for(; nIndex < stDeviceList.nDeviceNum; ++nIndex) {
            RCLCPP_INFO(rclcpp::get_logger("camera"),"device:[%d]", nIndex);
            MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[nIndex];
            if (NULL == pDeviceInfo)
            {
                continue;
            } 
            PrintDeviceInfo(pDeviceInfo);
            break;   // 找到一个可用的,直接退出
        }
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "Find No Devices!");
        return -1;

    }
    // 是否有可用设备
    if(NULL == stDeviceList.pDeviceInfo[nIndex]) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "no device aviliable!");
        return -1;
    }
    // 创建句柄
    nRet = MV_CC_CreateHandle(&handle_, stDeviceList.pDeviceInfo[nIndex]);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_CreateHandle fail,code[%d]", nRet);
        return nRet;
    }
    // 打开设备
    nRet = MV_CC_OpenDevice(handle_);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_OpenDevice fail,code[%d]", nRet);
        return nRet;
    }
    // 探测网络包大小  TODO:改成可配置
    if(true && stDeviceList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE) {
        int nPacketSize = MV_CC_GetOptimalPacketSize(handle_);
        if(nPacketSize > 0) {
            nRet = MV_CC_SetIntValueEx(handle_,"GevSCPSPacketSize",nPacketSize);
            if(nRet != MV_OK) {
                RCLCPP_WARN(rclcpp::get_logger("camera"), "Warning: MV_CC_SetIntValueEx Set Packet Size fail, code:[%d]", nRet);
            }
        } else {
            RCLCPP_WARN(rclcpp::get_logger("camera"), "Warning: MV_CC_GetOptimalPacketSize Set Packet Size fail, code:[%d]", nRet);
        }
    }
    RCLCPP_INFO(rclcpp::get_logger("camera"), "MV_CC_Initialize successful....");

    return MV_OK;
}

int HKCamera::start_camera() {
    // 设置模式属性
    int nRet = MV_OK;
    nRet = MV_CC_SetEnumValue(handle_, "TriggerMode", 0);
    //nRet = MV_CC_SetEnumValue(handle_, "PixelFormat", 0x02180014); // 目前 RGB  
    //MVCC_ENUMVALUE t = {0};
    //nRet = MV_CC_GetEnumValue(handle_, "PixelFormat", &t);

    // 开始取流
    nRet = MV_CC_StartGrabbing(handle_);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"),"MV_CC_StartGrabbing fail, code:[%d]",nRet);
        return nRet;
    }

    std::thread{work_thread,this->handle_}.detach();


}

void *HKCamera::work_thread(void* handle) {
    RCLCPP_INFO(rclcpp::get_logger("camera"), "into  work thread....");
    int nRet = MV_OK;
    MVCC_INTVALUE stParam;
    memset(&stParam,0,sizeof(MVCC_INTVALUE));
    nRet = MV_CC_GetIntValue(handle, "PayloadSize", &stParam);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"),"get PayloadSize fail, code[%d]",nRet);
        return NULL;
    }
    MV_FRAME_OUT_INFO_EX stImageInfo = {0};
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
    unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * stParam.nCurValue);
    //unsigned char *m_pBufForSaveImage = (unsigned char *)malloc(MAX_IMAGE_DATA_SIZE);
    if (NULL == pData)
    {
        return NULL;
    }
    unsigned int nDataSize = stParam.nCurValue;
    //MV_CC_PIXEL_CONVERT_PARAM stConvertParam = {0};

    while(true) {
        nRet = MV_CC_GetOneFrameTimeout(handle, pData, nDataSize, &stImageInfo, 1000);
        if(nRet == MV_OK) {
            RCLCPP_INFO(rclcpp::get_logger("camera"), "get one frame:weight:[%d], height:[%d], nFrameNum:[%d]",
            stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
        } else {
            RCLCPP_WARN(rclcpp::get_logger("camera"), "no data..");
            continue;
        }
        
        // opencv把图片打印出来

        cv::Mat frame = cv::Mat(stImageInfo.nHeight,stImageInfo.nWidth,CV_8UC3,pData).clone();
        // 原图太大了,按比例缩小一点
        cv::Mat dst;
        cv::resize(frame, dst,cv::Size(stImageInfo.nHeight/5,stImageInfo.nWidth/5));

        // 调试输出
        cv::imshow("hk_version", frame);
        cv::waitKey(0);
        
        // sleep 
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    free(pData);
    //free(m_pBufForSaveImage);

    return nullptr;
}

int HKCamera::stop_camera() {
    int nRet = MV_CC_StopGrabbing(handle_);
    if(nRet != MV_OK) {
        RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_StopGrabbing fail, code:[%d]", nRet);
        return nRet;
    }
    nRet = MV_CC_CloseDevice(handle_);
    if(nRet != MV_OK) {
       RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_CloseDevice fail, code:[%d]", nRet);
    }
    nRet = MV_CC_DestroyHandle(handle_); 
    if(nRet != MV_OK) {
      RCLCPP_ERROR(rclcpp::get_logger("camera"), "MV_CC_DestroyHandle fail, code:[%d]", nRet);
    }
    handle_ = NULL;
    MV_CC_Finalize();
    return MV_OK;
}

bool HKCamera::PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo) {
    if (NULL == pstMVDevInfo)
    {
        printf("The Pointer of pstMVDevInfo is NULL!\n");
        return false;
    }

    if (pstMVDevInfo->nTLayerType == MV_GIGE_DEVICE) {
        int nIp1 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
        int nIp2 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
        int nIp3 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
        int nIp4 = (pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

        // ch:打印当前相机ip和用户自定义名字 | en:print current ip and user defined name
        printf("Device Model Name: %s\n", pstMVDevInfo->SpecialInfo.stGigEInfo.chModelName);
        printf("CurrentIp: %d.%d.%d.%d\n" , nIp1, nIp2, nIp3, nIp4);
        //printf("UserDefinedName: %s\n\n" , pstMVDevInfo->SpecialInfo.stGigEInfo.chUserDefinedName);
    } else if (pstMVDevInfo->nTLayerType == MV_USB_DEVICE) {
        printf("Device Model Name: %s\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chModelName);
        //printf("UserDefinedName: %s\n\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName);
    } else {
        printf("Not support.\n");
    }

    return true;
}


HKCamera::~HKCamera() {
    if(handle_) {
        this->stop_camera();
    }
}

