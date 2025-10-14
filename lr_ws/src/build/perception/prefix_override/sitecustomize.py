import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/root/Lunar_ROADSTER/lr_ws/src/install/perception'
