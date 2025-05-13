/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 11:41:45
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-18 11:43:26
 * @Description:
 * @FilePath: /dcloud/models/tb_robot_app_version.go
 */
package models

import "time"

// 机器人程序版本信息表
type TbRobotAppVersion struct {
	Id              int64     `gorm:"column:id;type:bigint(20);primary_key;AUTO_INCREMENT;comment:Primary Key" json:"id"`
	RobotSn         string    `gorm:"column:robot_sn;type:varchar(128);comment:序列号" json:"robot_sn"`
	AppName         string    `gorm:"column:app_name;type:varchar(128);comment:应用名称" json:"app_name"`
	AppType         int       `gorm:"column:app_type;type:int(11);comment:应用程序类型" json:"app_type"`
	Version         string    `gorm:"column:version;type:varchar(48);comment:当前版本" json:"version"`
	VersionDesc     string    `gorm:"column:version_desc;type:varchar(10280);comment:版本描述" json:"version_desc"`
	FilePath        string    `gorm:"column:file_path;type:varchar(512);comment:文件路径" json:"file_path"`
	UpdateStatus    int       `gorm:"column:update_status;type:int(11);comment:升级状态  1-未升级 2-升级中 3-升级成功 4-升级失败" json:"update_status"`
	UpdateLogs      string    `gorm:"column:update_logs;type:varchar(512);comment:升级日志" json:"update_logs"`
	UpdateStartTime time.Time `gorm:"column:update_start_time;type:datetime;comment:升级开始时间" json:"update_start_time"`
	UpdateEndTime   time.Time `gorm:"column:update_end_time;type:datetime;comment:升级结束时间" json:"update_end_time"`
	Operator        string    `gorm:"column:operator;type:varchar(128);comment:操作人" json:"operator"`
}

func (m *TbRobotAppVersion) TableName() string {
	return "tb_robot_app_version"
}
