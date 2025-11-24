from setuptools import setup

package_name = 'late_fusion'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=[
        'numpy',
        'opencv-python',
        'shapely',
        'scikit-learn'
    ],
    entry_points={
        'console_scripts': [
            'fusion_node = late_fusion.fusion_node:main'
        ],
    },
)
