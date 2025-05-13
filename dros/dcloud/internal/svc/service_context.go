/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 11:08:48
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-18 14:32:28
 * @Description:
 * @FilePath: /dcloud/internal/svc/service_context.go
 */
package svc

import (
	"dcloud/internal/config"
	"dcloud/repo"
	"fmt"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
	"gorm.io/gorm/schema"
)

type ServiceContext struct {
	Config config.Config

	AppVersionRepo      repo.AppVersionRepo
	RobotInfoRepo       repo.RobotInfoRepo
	RobotAppVersionRepo repo.RobotAppVersionRepo
}

func NewServiceContext(c config.Config) *ServiceContext {
	// 初始化gorm
	level := logger.Default.LogMode(logger.Warn)
	if c.Mysql.EnablePrintSQL == 1 {
		level = logger.Default.LogMode(logger.Info)
	}
	db, err := gorm.Open(mysql.Open(c.Mysql.DataSource), &gorm.Config{
		SkipDefaultTransaction: false,
		NamingStrategy: schema.NamingStrategy{
			TablePrefix: "tb_",
		},
		Logger: level,
	})
	if err != nil {
		fmt.Println("init gorm fail:", err)
		//panic(err)
	}
	sqlDB, _ := db.DB()
	sqlDB.SetMaxIdleConns(c.Mysql.IdleConn)    // 空闲连接池数量
	sqlDB.SetMaxOpenConns(c.Mysql.MaxOpenConn) // 最大连接数量
	sqlDB.SetConnMaxLifetime(time.Hour)        // 设置可复用最大时间

	return &ServiceContext{
		Config:              c,
		AppVersionRepo:      repo.NewAppVersionRepo(db),
		RobotInfoRepo:       repo.NewRobotInfoRepo(db),
		RobotAppVersionRepo: repo.NewRobotAppVersionRepo(db),
	}
}
