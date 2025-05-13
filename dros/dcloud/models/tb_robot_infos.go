/*
 * @Author: hawrkchen
 * @Date: 2025-03-13 11:54:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-14 10:00:49
 * @Description:
 * @FilePath: /dcloud/models/tb_robot_infos.go
 */
package models

import "time"

// 机器人信息表
type TbRobotInfos struct {
	Id              int64     `gorm:"column:id;type:bigint(20);primary_key;AUTO_INCREMENT;comment:Primary Key" json:"id"`
	RobotSn         string    `gorm:"column:robot_sn;type:varchar(128);comment:序列号;NOT NULL" json:"robot_sn"`
	RobotName       string    `gorm:"column:robot_name;type:varchar(128);comment:机器人名称" json:"robot_name"`
	RobotType       int       `gorm:"column:robot_type;type:tinyint(4);comment:机器人类型" json:"robot_type"`
	FirmwareVersion string    `gorm:"column:firmware_version;type:varchar(48);comment:固件版本" json:"firmware_version"`
	Region          string    `gorm:"column:region;type:varchar(128);comment:地区" json:"region"`
	RobotIp         string    `gorm:"column:robot_ip;type:varchar(32);comment:IP地址" json:"robot_ip"`
	RobotPort       int       `gorm:"column:robot_port;type:int(11);comment:端口号" json:"robot_port"`
	Address         string    `gorm:"column:address;type:varchar(512);comment:详细地址" json:"address"`
	BatteryLevel    float64   `gorm:"column:battery_level;type:float;comment:电池电量(50)" json:"battery_level"`
	CurVersion      string    `gorm:"column:cur_version;type:varchar(48);comment:当前版本" json:"cur_version"`
	SubVersion      string    `gorm:"column:sub_version;type:varchar(10280);comment:子版本号(json格式)" json:"sub_version"`
	RobotStatus     int       `gorm:"column:robot_status;type:tinyint(4);comment:当前状态  1-正常 2-升级中 3-故障 4-废弃" json:"robot_status"`
	ErrLogs         string    `gorm:"column:err_logs;type:varchar(512);comment:升级返回的错误日志" json:"err_logs"`
	Operator        string    `gorm:"column:operator;type:varchar(128);comment:操作用户" json:"operator"`
	CreateTime      time.Time `gorm:"column:create_time;type:datetime;default:CURRENT_TIMESTAMP;comment:创建时间" json:"create_time"`
	UpgradeStatus   int       `gorm:"column:upgrade_status;type:tinyint(4);comment:1-正常,2-升级中 3-升级成功;4-升级失败； 5-回滚中,6-回滚成功; 7-回滚失败;" json:"upgrade_status"`
	UpdateStartTime time.Time `gorm:"column:update_start_time;type:datetime;comment:升级开始时间" json:"update_start_time"`
	UpdateEndTime   time.Time `gorm:"column:update_end_time;type:datetime;comment:升级结束时间" json:"update_end_time"`
}

func (m *TbRobotInfos) TableName() string {
	return "tb_robot_infos"
}
