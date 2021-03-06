"""Launch camera."""
# Copyright 2022 HarvestX Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ament_index_python import get_package_share_path

from launch import LaunchDescription

from launch_ros.actions import Node


def generate_launch_description():
    """Generate launch description."""
    this_pkg_path = get_package_share_path('param_test')
    config = this_pkg_path / 'config' / 'param.yaml'

    node = Node(
        name='param_test',
        package='param_test',
        executable='param_test',
        output='screen',
        parameters=[
            config
        ],

    )

    return LaunchDescription([node])
