// Copyright 2022 HarvestX Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
  enum color_idx
  {
    R,
    G,
    B
  };

public:
  explicit Talker()
  : Node("param_tester")
  {
    std::vector<std::string> names;
    this->declare_parameter<std::vector<std::string>>("names");
    this->get_parameter("names", names);

    std::vector<std::vector<double>> colors;

    // Load color parameter
    for (auto name : names) {
      auto param_name = "colors." + name; // Ex: colors.bob

      // NOTE: type std::vector<float> does not supported for ROS2 param
      std::vector<double> tmp;
      this->declare_parameter<std::vector<double>>(param_name);
      this->get_parameter(param_name, tmp);

      colors.emplace_back(tmp);
    }

    assert(names.size() == colors.size());

    // Show info
    for (int64_t i = 0; i < static_cast<int64_t>(names.size()); ++i) {
      RCLCPP_INFO(
        this->get_logger(),
        "Name: %s, Color R: %.3lf G: %.3lf B: %.3lf",
        names.at(i).c_str(),
        colors.at(i).at(color_idx::R),
        colors.at(i).at(color_idx::G),
        colors.at(i).at(color_idx::B)
      );
    }
  }

private:
};

int main(int argc, char * argv[])
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);
  rclcpp::init(argc, argv);

  auto node = std::make_shared<Talker>();
  rclcpp::spin_some(node);
  rclcpp::shutdown();

  return 0;
}
