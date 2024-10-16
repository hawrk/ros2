import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/byd/src/ros2/point_cloud_ws/point_cloud_pub/install/point_cloud_pub'
