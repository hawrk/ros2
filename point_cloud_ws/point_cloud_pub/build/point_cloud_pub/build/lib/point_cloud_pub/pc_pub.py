'''
Author: hawrkchen hawrk2012@163.com
Date: 2024-10-15 15:15:30
LastEditors: hawrkchen hawrk2012@163.com
LastEditTime: 2024-10-16 09:37:19
FilePath: /point_cloud_pub/point_cloud_pub/pc_pub.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2
from sensor_msgs.msg import PointField
from sensor_msgs_py import point_cloud2
from std_msgs.msg import Header

class PointCloudPublisher(Node):
    rate = 30
    moving = True
    width = 100
    height = 100
    
    header = Header()
    header.frame_id = "camera_link"

    dtype = PointField.FLOAT32
    point_step = 16
    fields = [PointField(name='x', offset=0, datatype=dtype, count=1),
            PointField(name='y', offset=4, datatype=dtype, count=1),
            PointField(name='z', offset=8, datatype=dtype, count=1),
            PointField(name='intensity', offset=12, datatype=dtype, count=1)]


    def __init__(self, name): 
        super().__init__('point_cloud_publisher')
        self.publisher_ = self.create_publisher(PointCloud2, 'point_cloud', 10)
        timer_period = 1.0 / self.rate  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.counter = 0

    def timer_callback(self):
        self.header.stamp = self.get_clock().now().to_msg()
        x, y = np.meshgrid(np.linspace(-2, 2, self.width), np.linspace(-2, 2, self.height))
        z = 0.5 * np.sin(2*x-self.counter/10.0) * np.sin(2*y)
        points = np.array([x, y, z, z]).reshape(4, -1).T
        pc2_msg = point_cloud2.create_cloud(self.header, self.fields, points)
        self.publisher_.publish(pc2_msg)

        if self.moving:
            self.counter += 1

# 这里的main不再是__main__, 而是point_cloud_pub.py的名字
def main(args=None):
    rclpy.init(args=args)
    node = PointCloudPublisher("pc_node")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()