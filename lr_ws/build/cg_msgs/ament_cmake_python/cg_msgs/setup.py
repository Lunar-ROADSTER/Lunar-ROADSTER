from setuptools import find_packages
from setuptools import setup

setup(
    name='cg_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('cg_msgs', 'cg_msgs.*')),
)
