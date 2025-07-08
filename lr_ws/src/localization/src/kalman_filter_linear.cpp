/**
 * @file kalman_filter_linear.cpp
 * @brief Linear Kalman Filter implementation for state estimation in localization systems.
 *
 * This module implements a standard discrete-time linear Kalman filter with configurable model parameters.
 * It supports both initialization with a prior estimate and zero-initialization, as well as prediction and update steps.
 *
 * The filter uses the classic state-space model:
 *   - Prediction:
 *     x̂ₖ₋ = A·x̂ₖ₋₁
 *     Pₖ₋ = A·Pₖ₋₁·Aᵀ + Q
 *   - Update:
 *     Kₖ = Pₖ₋·Hᵀ·(H·Pₖ₋·Hᵀ + R)⁻¹
 *     x̂ₖ = x̂ₖ₋ + Kₖ·(zₖ - H·x̂ₖ₋)
 *     Pₖ = (I - Kₖ·H)·Pₖ₋
 *
 * This implementation is generic and can be used for sensor fusion and localization tasks in mobile robotics.
 *
 * @version 1.0.0
 * @date 2025-07-07
 *
 * Maintainer: Bhaswanth Ayapilla, Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - A: State transition matrix
 * - H: Observation matrix
 * - Q: Process noise covariance
 * - R: Observation noise covariance
 * - P: Initial estimate error covariance
 * - z: Measurement vector
 *
 * Methods:
 * - init(): Initialize with zero or a given state.
 * - predict(): Predict the next state using the model.
 * - update(): Update the state with a measurement.
 *
 * @credit Based on standard Kalman Filter theory and Eigen library usage.
 */

#include "localization/kalman_filter_linear.hpp"

lr::localization::KalmanFilterLinear::KalmanFilterLinear() {}

lr::localization::KalmanFilterLinear::KalmanFilterLinear(
    const Eigen::MatrixXd &A,
    const Eigen::MatrixXd &H,
    const Eigen::MatrixXd &Q,
    const Eigen::MatrixXd &R,
    const Eigen::MatrixXd &P)
    : A(A), H(H), Q(Q), R(R), P0(P), initialized(false),
      I(A.rows(), A.rows()), x_hat(A.rows()), x_hat_new(A.rows())
{
  I.setIdentity();
}

void lr::localization::KalmanFilterLinear::init(const Eigen::VectorXd &x0)
{
  x_hat = x0;
  P = P0;
  initialized = true;
}

void lr::localization::KalmanFilterLinear::init()
{
  x_hat.setZero();
  P = P0;
  initialized = true;
}

void lr::localization::KalmanFilterLinear::predict()
{
  // Predict next state and uncertainty
  x_hat_new = A * x_hat;
  P = A * P * A.transpose() + Q;
}


void lr::localization::KalmanFilterLinear::update(const Eigen::VectorXd &z)
{
  if (!initialized)
    throw std::runtime_error("Filter is not initialized!");

  // Calculate Kalman Gain
  K = P * H.transpose() * (H * P * H.transpose() + R).inverse();

  // Update state and uncertainty
  x_hat_new += K * (z - H * x_hat_new);
  P = (I - K * H) * P;

  // Set next state
  x_hat = x_hat_new;
}