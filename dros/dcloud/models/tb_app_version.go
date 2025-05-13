/*
 * @Author: hawrkchen
 * @Date: 2025-03-12 14:08:24
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-18 15:42:45
 * @Description:
 * @FilePath: /dcloud/models/tb_app_version.go
 */
package models

import "time"

// 应用版本表
type TbAppVersion struct {
	Id          int       `gorm:"column:id;type:int(11);primary_key;AUTO_INCREMENT;comment:Primary Key" json:"id"`
	AppName     string    `gorm:"column:app_name;type:varchar(128);comment:应用名称" json:"app_name"`
	AppVersion  string    `gorm:"column:app_version;type:varchar(128);comment:版本号" json:"app_version"`
	VersionDesc string    `gorm:"column:version_desc;type:varchar(255);comment:版本描述" json:"version_desc"`
	PkgName     string    `gorm:"column:pkg_name;type:varchar(128);comment:包名称" json:"pkg_name"`
	OpUser      string    `gorm:"column:op_user;type:varchar(128);comment:操作用户" json:"op_user"`
	CreateTime  time.Time `gorm:"column:create_time;type:datetime;default:CURRENT_TIMESTAMP;comment:创建时间" json:"create_time"`
	UpdateTime  time.Time `gorm:"column:update_time;type:datetime;comment:更新时间" json:"update_time"`
}

func (m *TbAppVersion) TableName() string {
	return "tb_app_version"
}
