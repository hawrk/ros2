/*
 * @Author: hawrkchen
 * @Date: 2025-03-11 14:35:22
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 10:25:22
 * @Description:
 * @FilePath: /dcloud/pkg/dversion/dversion.go
 */
package dversion

import (
	"fmt"
	"strconv"
	"strings"
)

type DVersion struct {
	Major int32 // 主版本号
	Minor int32 // 副版本号
	Patch int32 // 小版本号 （修订版本号)
}

// GenerateVersion generate version string
// ver：当前版本号
// verType: 1 :主版本号 2：次版本号 3：修订号
func GenerateVersion(ver string, verType int32) string {
	if ver == "" { // 第一次无版本号，直接返回初始版本号
		version := NewVersion(1, 0, 0)
		return version.ToString()
	}

	version, err := ParseVersion(ver)
	if err != nil { // 解析版本号字符串
		fmt.Printf("ParseVersion error: %s", err.Error())
		return ""
	}

	switch verType {
	case 1:
		version.IncreMajor()
	case 2:
		version.IncreMinor()
	case 3:
		version.IncrePatch()
	default:
		return ""
	}
	fmt.Println("get version:", version.ToString())
	return version.ToString()

}

// NewVersion 第一个版本号
func NewVersion(major, minor, patch int32) *DVersion {
	return &DVersion{
		Major: major,
		Minor: minor,
		Patch: patch,
	}
}

// ParseVersion 解析传入的版本号字符串
func ParseVersion(versionStr string) (*DVersion, error) {
	// 解析版本号字符串
	parts := strings.Split(versionStr, ".")
	if len(parts) != 3 {
		return nil, fmt.Errorf("invalid version string: %s", versionStr)
	}

	major, err := strconv.Atoi(parts[0])
	if err != nil {
		return nil, fmt.Errorf("invalid major version: %s", parts[0])
	}

	minor, err := strconv.Atoi(parts[1])
	if err != nil {
		return nil, fmt.Errorf("invalid minor version: %s", parts[1])
	}

	patch, err := strconv.Atoi(parts[2])
	if err != nil {
		return nil, fmt.Errorf("invalid patch version: %s", parts[2])
	}

	return &DVersion{
		Major: int32(major),
		Minor: int32(minor),
		Patch: int32(patch),
	}, nil
}

// IncreMajor 主版本号更新， 副版本号和修订号置为0
func (v *DVersion) IncreMajor() {
	v.Major += 1
	v.Minor = 0
	v.Patch = 0
}

// IncreMinor 副版本号更新， 修订号置为0
func (v *DVersion) IncreMinor() {
	v.Minor += 1
	v.Patch = 0
}

// IncrePatch 修订号更新
func (v *DVersion) IncrePatch() {
	v.Patch += 1
}

// ToString 版本号字符串
func (v *DVersion) ToString() string { // 返回版本号格式
	return fmt.Sprintf("%d.%d.%d", v.Major, v.Minor, v.Patch)
}
