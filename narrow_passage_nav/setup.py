from setuptools import setup
import os
from glob import glob

package_name = 'narrow_passage_nav'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ysc',
    maintainer_email='2627283077@qq.com',
    description='Narrow passage navigation system',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'depth_perception_node = narrow_passage_nav.depth_perception_node:main',
            'mode_decision_node = narrow_passage_nav.mode_decision_node:main',
            'safety_fusion_node = narrow_passage_nav.safety_fusion_node:main',
            'decision_csv_logger = narrow_passage_nav.decision_csv_logger:main',
        ],
    },
)
