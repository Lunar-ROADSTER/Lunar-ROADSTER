// -*-c++-*--------------------------------------------------------------------
// Copyright 2023 Bernd Pfrommer <bernd.pfrommer@gmail.com>
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

#ifndef SPINNAKER_CAMERA_DRIVER__CAMERA_DRIVER_HPP_
#define SPINNAKER_CAMERA_DRIVER__CAMERA_DRIVER_HPP_

#include <image_transport/image_transport.hpp>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <spinnaker_camera_driver/camera.hpp>

namespace spinnaker_camera_driver
{
class CameraDriver : public rclcpp::Node
{
public:
  explicit CameraDriver(const rclcpp::NodeOptions & options);
  ~CameraDriver();

private:
  std::shared_ptr<image_transport::ImageTransport> imageTransport_;
  std::shared_ptr<Camera> camera_;
};
}  // namespace spinnaker_camera_driver
#endif  // SPINNAKER_CAMERA_DRIVER__CAMERA_DRIVER_HPP_
