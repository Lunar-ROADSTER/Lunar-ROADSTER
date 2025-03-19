from setuptools import find_packages
from setuptools import setup

setup(
    name='lx_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('lx_msgs', 'lx_msgs.*')),
)
