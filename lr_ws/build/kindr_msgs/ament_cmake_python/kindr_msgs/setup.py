from setuptools import find_packages
from setuptools import setup

setup(
    name='kindr_msgs',
    version='0.3.4',
    packages=find_packages(
        include=('kindr_msgs', 'kindr_msgs.*')),
)
