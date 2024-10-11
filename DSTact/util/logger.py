import logging
import os

logpath = "../log"
if not os.path.exists(logpath):
    os.makedirs(logpath)

logger = logging.getLogger("..log/DSTact.log")
logger.setLevel(logging.DEBUG)

formatter = logging.Formatter('%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s')

file_handler = logging.FileHandler('../log/DSTact.log')
file_handler.setLevel(logging.DEBUG)
file_handler.setFormatter(formatter)

logger.addHandler(file_handler)

