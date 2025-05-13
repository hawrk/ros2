/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 11:51:12
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 11:07:33
 * @Description:
 * @FilePath: /dcloud/pkg/dhttp/dhttp.go
 */
// package dhttp

package dhttp

import (
	"bytes"
	"encoding/json"
	"errors"
	"io"
	"net/http"

	"github.com/zeromicro/go-zero/core/logx"
)

type DROSResp struct {
	Code    int32  `json:"code"`
	Data    string `json:"data"`
	Message string `json:"message"`
}

// SendHttpRequest
// ret code, msg, data, error
func SendHttpRequest(url string, method string,
	headers map[string]string, body map[string]any) (int32, string, string, error) {

	str := BuildHttpBody(body)
	if str == "" {
		return -1, "", "", errors.New("body is empty")
	}
	req, err := http.NewRequest(method, url, bytes.NewBufferString(str))
	if err != nil {
		logx.Errorf("error create http request: %v", err)
		return -1, "", "", err
	}
	for k, v := range headers {
		req.Header.Set(k, v)
	}
	// 设置　Content-Type　为　application/json
	req.Header.Set("Content-Type", "application/json")

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		logx.Errorf("error send http request: %v", err)
		return -1, "", "", err
	}
	defer func(Body io.ReadCloser) {
		err := Body.Close()
		if err != nil {
			logx.Errorf("error close http response body: %v", err)
		}
	}(resp.Body)

	// 读取返回数据
	bodyBytes, err := io.ReadAll(resp.Body)
	if err != nil {
		logx.Errorf("error read http response body: %v", err)
		return -1, "", "", err
	}
	// 解析返回数据
	var drsp DROSResp
	err = json.Unmarshal(bodyBytes, &drsp)
	if err != nil {
		logx.Errorf("error unmarshal json body: %v", err)
		return -1, "", "", err
	}

	return drsp.Code, drsp.Message, drsp.Data, nil
}

func BuildHttpBody(params map[string]interface{}) string {
	jsonBody, err := json.Marshal(params)
	if err != nil {
		logx.Errorf("error marshal json body: %v", err)
		return ""
	}
	return string(jsonBody)
}
