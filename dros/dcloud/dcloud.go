/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 11:08:48
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-12 16:15:16
 * @Description:
 * @FilePath: /dcloud/dcloud.go
 */
package main

import (
	"flag"
	"fmt"
	"net/http"

	"dcloud/internal/config"
	"dcloud/internal/handler"
	"dcloud/internal/svc"

	"github.com/zeromicro/go-zero/core/conf"
	"github.com/zeromicro/go-zero/rest"
)

var configFile = flag.String("f", "etc/dcloud-api.yaml", "the config file")

func main() {
	flag.Parse()

	var c config.Config
	conf.MustLoad(*configFile, &c)

	ctx := svc.NewServiceContext(c)

	//server := rest.MustNewServer(c.RestConf)
	server := rest.MustNewServer(c.RestConf, rest.WithCustomCors(
		func(header http.Header) {
			header.Set("Access-Control-Allow-Origin", "*")                                                   // 这是允许访问所有域
			header.Add("Access-Control-Allow-Headers", "x-requested-with,x-token,Access-Token,Content-Type") // 这是允许访问所有域
			header.Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
			//header.Add("Access-Control-Expose-Headers", "Content-Disposition")
		}, nil))

	defer server.Stop()

	handler.RegisterHandlers(server, ctx)

	fmt.Printf("Starting server at %s:%d...\n", c.Host, c.Port)
	server.Start()
}
