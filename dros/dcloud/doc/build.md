1. 官方生成项目命令　goctl api new dcloud，会在项目文件下生成api文件，不应采用这种方式，api文件应该归在api目录下

2. 正确的生成方式，　先自行构建生成dcloud/api/xxx.api目录，　然后定义好xxx.api接口，再用
　　　goctl api go -api dcloud/api/ota.api -dir dcloud -style=go_zero　生成
