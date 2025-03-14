/*
 * Copyright (c) 2014, Peter Fankhauser, Christian Gehring, Hannes Sommer, Paul Furgale, Remo Diethelm
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Autonomous Systems Lab, ETH Zurich nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Peter Fankhauser, Christian Gehring, Hannes Sommer, Paul Furgale,
 * Remo Diethelm BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef KINDR_ROS__ROSTFPOSE_HPP_
#define KINDR_ROS__ROSTFPOSE_HPP_


// kindr
#include <kindr/Core>

// ros
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Vector3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>


namespace kindr_ros
{


template<typename PrimType_, typename Position_, typename Rotation_>
inline static void convertFromRosTf(
  const tf2::Transform & tfTransform,
  kindr::HomogeneousTransformation<PrimType_, Position_,
  Rotation_> & pose)
{
  typedef Position_ Position;
  typedef Rotation_ Rotation;

  // This is the definition of TF.
  typedef kindr::RotationMatrix<PrimType_> RotationMatrixTfLike;

  const tf2::Vector3 & rowX = tfTransform.getBasis().getRow(0);
  const tf2::Vector3 & rowY = tfTransform.getBasis().getRow(1);
  const tf2::Vector3 & rowZ = tfTransform.getBasis().getRow(2);

  RotationMatrixTfLike rotation;
  rotation.setMatrix(
    rowX.x(), rowX.y(), rowX.z(),
    rowY.x(), rowY.y(), rowY.z(),
    rowZ.x(), rowZ.y(), rowZ.z());

  Position position(tfTransform.getOrigin().getX(),
    tfTransform.getOrigin().getY(),
    tfTransform.getOrigin().getZ());

  pose.getRotation() = Rotation(rotation);
  pose.getPosition() = position;
}

template<typename Rotation_>
inline static void convertToRosTfQuaternion(tf2::Quaternion & tfQuat, const Rotation_ & rotation)
{
  const auto quat = kindr::RotationQuaternion<typename Rotation_::Scalar>(rotation);
  tfQuat = tf2::Quaternion(quat.x(), quat.y(), quat.z(), quat.w());
}

template<typename PrimType_, typename Position_, typename Rotation_>
inline static void convertToRosTf(
  const kindr::HomogeneousTransformation<PrimType_, Position_,
  Rotation_> & pose, tf2::Transform & tfTransform)
{
  // This is the definition of TF.
  typedef kindr::RotationMatrix<PrimType_> RotationMatrixTfLike;
  Eigen::Matrix3d rotationMatrix(RotationMatrixTfLike(pose.getRotation()).matrix());
  tf2::Matrix3x3 tfRotationMatrix(rotationMatrix(0, 0), rotationMatrix(0, 1), rotationMatrix(0, 2),
    rotationMatrix(1, 0), rotationMatrix(1, 1), rotationMatrix(1, 2),
    rotationMatrix(2, 0), rotationMatrix(2, 1), rotationMatrix(2, 2));
  tfTransform.setBasis(tfRotationMatrix);

  // less accurate by quaternion:
//  tf2::Quaternion tfQuat;
//  convertToRosTfQuaternion(tfQuat, pose.getRotation());
//  tfTransform.setRotation(tfQuat);

  tfTransform.setOrigin(
    tf2::Vector3(
      pose.getPosition().x(),
      pose.getPosition().y(),
      pose.getPosition().z()));
}


}  // namespace kindr_ros

#endif  // KINDR_ROS__ROSTFPOSE_HPP_
