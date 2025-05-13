/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 11:08:48
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-12 11:34:42
 * @Description:
 * @FilePath: /dcloud/internal/config/config.go
 */
package config

import "github.com/zeromicro/go-zero/rest"

type Config struct {
	rest.RestConf

	Secret struct {
		GcmKey string
	}

	Mysql struct {
		DataSource     string
		IdleConn       int
		MaxOpenConn    int
		EnablePrintSQL int
	}
}
