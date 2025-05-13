/*
 * @Author: hawrkchen
 * @Date: 2025-03-12 14:11:26
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 10:49:15
 * @Description:
 * @FilePath: /dcloud/repo/app_version.go
 */
package repo

import (
	"context"
	"dcloud/models"
	"time"

	"gorm.io/gorm"
)

type AppVersionRepo interface {
	CreateAppVersion(ctx context.Context, appName, ver, desc, pkgName, user string) error
	GetAppVersion(ctx context.Context, appName string, page, limit int) ([]*models.TbAppVersion, error)
	UpdateAppVersion(ctx context.Context, appName, ver, desc, pkgName, user string) error
	GetLatestVersion(ctx context.Context, appName string) (string, error)
}

type DefaultAppVersion struct {
	DB *gorm.DB
}

func NewAppVersionRepo(conn *gorm.DB) AppVersionRepo {
	return &DefaultAppVersion{
		DB: conn,
	}
}

func (r *DefaultAppVersion) CreateAppVersion(ctx context.Context, appName, ver, desc, pkgName, user string) error {
	appVersion := models.TbAppVersion{
		AppName:     appName,
		AppVersion:  ver,
		PkgName:     pkgName,
		VersionDesc: desc,
		OpUser:      user,
		UpdateTime:  time.Now(),
	}
	return r.DB.Create(&appVersion).Error
}

// 根据 应用名称 获取应用版本列表
func (r *DefaultAppVersion) GetAppVersion(ctx context.Context, appName string, page, limit int) ([]*models.TbAppVersion, error) {
	var appVersions []*models.TbAppVersion
	err := r.DB.Model(&models.TbAppVersion{}).Where("app_name = ?", appName).Offset((page - 1) * limit).Limit(limit).Find(&appVersions).Error
	return appVersions, err
}

func (r *DefaultAppVersion) UpdateAppVersion(ctx context.Context, appName, ver, desc, pkgName, user string) error {
	appVersion := models.TbAppVersion{
		AppVersion:  ver,
		PkgName:     pkgName,
		VersionDesc: desc,
		OpUser:      user,
		UpdateTime:  time.Now(),
	}
	return r.DB.Model(&models.TbAppVersion{}).Where("app_name = ?", appName).Updates(&appVersion).Error
}

// 取程序当前最新版本号
func (r *DefaultAppVersion) GetLatestVersion(ctx context.Context, appName string) (string, error) {
	var appVersion models.TbAppVersion
	err := r.DB.Model(&models.TbAppVersion{}).Where("app_name = ?", appName).Order("create_time DESC").First(&appVersion).Error
	if err != nil {
		return "", err
	}
	return appVersion.AppVersion, nil
}
