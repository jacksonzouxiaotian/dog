from setuptools import setup

package_name = 'traversability_fsm'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/demo.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ysc',
    maintainer_email='2627283077@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'failure_monitor = traversability_fsm.failure_monitor:main',
            'traversability_fsm = traversability_fsm.traversability_fsm:main',
            'motion_gate = traversability_fsm.motion_gate:main',
        ],
    },
)
