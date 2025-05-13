/*
 * @Author: hawrkchen
 * @Date: 2025-03-13 11:53:21
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 10:39:04
 * @Description:
 * @FilePath: /dcloud/repo/robot_infos.go
 */
package repo

import (
	"context"
	"dcloud/models"
	"time"

	"gorm.io/gorm"
)

type RobotInfoRepo interface {
	GetRobotInfoBySn(ctx context.Context, sn string) (models.TbRobotInfos, error)
	GetAllRobotInfo(ctx context.Context, page, limit int) ([]*models.TbRobotInfos, error)
	GetNormalRobotInfo(ctx context.Context) ([]*models.TbRobotInfos, error)
	UpdateBatteryBySn(ctx context.Context, sn string, batteryLevel float32) error
	UpdateStatusBysn(ctx context.Context, sn string, status int, errLogs string, startTime, endTime time.Time, operator string) error
}

type DefaultRobotInfo struct {
	DB *gorm.DB
}

func NewRobotInfoRepo(conn *gorm.DB) RobotInfoRepo {
	return &DefaultRobotInfo{
		DB: conn,
	}
}

// GetRobotInfoBySn 根据机器人序列号获取机器人信息
func (r *DefaultRobotInfo) GetRobotInfoBySn(ctx context.Context, sn string) (models.TbRobotInfos, error) {
	var robotInfo models.TbRobotInfos
	err := r.DB.Model(&models.TbRobotInfos{}).Where("robot_sn = ?", sn).Find(&robotInfo).Error
	if err != nil {
		return models.TbRobotInfos{}, err
	}
	return robotInfo, nil
}

// GetAllRobotInfo 获取所有机器人信息
func (r *DefaultRobotInfo) GetAllRobotInfo(ctx context.Context, page, limit int) ([]*models.TbRobotInfos, error) {
	var robotInfo []*models.TbRobotInfos
	if page == 0 || limit == 0 {
		err := r.DB.Model(&models.TbRobotInfos{}).Find(&robotInfo).Error
		if err != nil {
			return nil, err
		}
	} else {
		err := r.DB.Model(&models.TbRobotInfos{}).Offset((page - 1) * limit).Limit(limit).Find(&robotInfo).Error
		if err != nil {
			return nil, err
		}
	}
	return robotInfo, nil
}

// GetNormalRobotInfo 获取正常机器人信息
// 状态正常，电量大于10
func (r *DefaultRobotInfo) GetNormalRobotInfo(ctx context.Context) ([]*models.TbRobotInfos, error) {
	var robotInfo []*models.TbRobotInfos
	err := r.DB.Model(&models.TbRobotInfos{}).Where("robot_status = ? and battery_level > ?", 1, 10.0).Find(&robotInfo).Error
	if err != nil {
		return nil, err
	}
	return robotInfo, nil
}

// UpdateBatteryBySn 根据机器人序列号更新机器人电量信息
func (r *DefaultRobotInfo) UpdateBatteryBySn(ctx context.Context, sn string, batteryLevel float32) error {
	err := r.DB.Model(&models.TbRobotInfos{}).Where("robot_sn = ?", sn).Update("battery_level", batteryLevel).Error
	if err != nil {
		return err
	}
	return nil
}

// UpdateStatusBysn 根据机器人序列号更新机器人状态   －－废弃，机器人升级更新状态在tb_robot_app_version表维护
func (r *DefaultRobotInfo) UpdateStatusBysn(ctx context.Context, sn string, status int, errLogs string, startTime, endTime time.Time, operator string) error {

	result := r.DB.Model(&models.TbRobotInfos{}).Where("robot_sn = ?", sn)
	if status > 0 {
		result.Update("upgrade_status", status)
	}
	if errLogs != "" {
		result.Update("err_logs", errLogs)
	}
	if !startTime.IsZero() {
		result.Update("update_start_time", startTime)
	}
	if !endTime.IsZero() {
		result.Update("update_end_time", endTime)
	}
	if operator != "" {
		result.Update("operator", operator)
	}

	return result.Error
}
