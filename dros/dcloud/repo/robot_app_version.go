/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 11:42:16
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-26 10:02:51
 * @Description:
 * @FilePath: /dcloud/repo/robot_app_version.go
 */
package repo

import (
	"context"
	"dcloud/models"

	"gorm.io/gorm"
)

type RobotAppVersionRepo interface {
	GetRobotAppVersion(ctx context.Context, sn, appName string) ([]*models.TbRobotAppVersion, error)
	GetRobotAppVersionByAppName(ctx context.Context, sn string, appName string) (models.TbRobotAppVersion, error)
	UpdateRobotAppVersion(ctx context.Context, robotSn, appName string, robotAppVersion *models.TbRobotAppVersion) error
	UpdateRobotAppStatus(ctx context.Context, sn string, appName string, status int) error
}

type DefaultRobotAppVersion struct {
	DB *gorm.DB
}

func NewRobotAppVersionRepo(conn *gorm.DB) RobotAppVersionRepo {
	return &DefaultRobotAppVersion{
		DB: conn,
	}
}

// GetRobotAppVersion 根据sn, app_name返回多条数据
func (r *DefaultRobotAppVersion) GetRobotAppVersion(ctx context.Context, sn, appName string) ([]*models.TbRobotAppVersion, error) {
	var robotAppVersions []*models.TbRobotAppVersion
	result := r.DB.Model(models.TbRobotAppVersion{}).Where("robot_sn = ?", sn)
	if appName != "" {
		result = result.Where("app_name = ?", appName)
	}
	err := result.Find(&robotAppVersions).Error
	if err != nil {
		return nil, err
	}
	return robotAppVersions, nil
}

// GetRobotAppVersionByAppName 根据sn和appName返回数据，只有单条记录
func (r *DefaultRobotAppVersion) GetRobotAppVersionByAppName(ctx context.Context, sn string, appName string) (models.TbRobotAppVersion, error) {
	var robotAppVersion models.TbRobotAppVersion
	result := r.DB.Model(models.TbRobotAppVersion{}).Where("robot_sn = ? and app_name = ?", sn, appName).Find(&robotAppVersion)
	if result.Error != nil {
		return models.TbRobotAppVersion{}, result.Error
	}
	return robotAppVersion, nil
}

func (r *DefaultRobotAppVersion) UpdateRobotAppVersion(ctx context.Context, robotSn, appName string, robotAppVersion *models.TbRobotAppVersion) error {
	err := r.DB.Model(models.TbRobotAppVersion{}).Where("robot_sn = ? and app_name = ?", robotSn, appName).Updates(robotAppVersion).Error
	if err != nil {
		return err
	}
	return nil
}

func (r *DefaultRobotAppVersion) UpdateRobotAppStatus(ctx context.Context, sn string, appName string, status int) error {
	err := r.DB.Model(models.TbRobotAppVersion{}).Where("robot_sn = ? AND app_name = ?", sn, appName).Update("update_status", status).Error
	if err != nil {
		return err
	}
	return nil
}
