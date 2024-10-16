'''
Author: hawrkchen hawrk2012@163.com
Date: 2024-10-15 15:11:59
LastEditors: hawrkchen hawrk2012@163.com
LastEditTime: 2024-10-15 16:42:33
FilePath: /point_cloud_pub/setup.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from setuptools import find_packages, setup

package_name = 'point_cloud_pub'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='byd',
    maintainer_email='hawrk2012@163.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            #自定义节点名 = 包名.节点文件名:节点函数名
            'pc_pub = point_cloud_pub.pc_pub:main',
        ],
    },
)
