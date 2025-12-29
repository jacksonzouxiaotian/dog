from setuptools import setup

package_name = 'narrow_passage_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    py_modules=[
        'cmd_vel_safety_arbiter',
        'cmd_vel_safety_fusion',
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            # 原来的节点
            'depth_narrow_passage_node = narrow_passage_controller.depth_narrow_passage_node:main',

            # 新增的两个节点
            'cmd_vel_safety_arbiter = cmd_vel_safety_arbiter:main',
            'cmd_vel_safety_fusion = cmd_vel_safety_fusion:main',
        ],
    },
)
