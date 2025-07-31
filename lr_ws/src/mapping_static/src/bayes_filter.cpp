/**
 * @file bayes_filter.cpp
 * @brief Implements a per-cell recursive Bayesian filter for elevation estimation in occupancy maps.
 *
 * This class models a simple 1D Kalman-like recursive estimator that fuses elevation observations over time
 * to provide a smoothed, variance-aware estimate of cell height. The filter is used to reduce measurement
 * noise in elevation maps constructed from LiDAR or depth sensors.
 *
 * Each cell maintains its own elevation mean and uncertainty (variance). Updates are applied using a
 * scalar Kalman gain computed from the current estimate uncertainty and the provided measurement noise.
 * Initial estimates are treated with high uncertainty to allow fast convergence.
 *
 * If a cell has not been observed before (elevation = 0), the Kalman gain is initialized to 1.0 to directly
 * adopt the first measurement.
 *
 * @version 1.0.0
 * @date 2025-07-27
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Core Methods:
 * - `BayesFilter()`: Initializes elevation to 0 and variance to a large value.
 * - `updateCell(z, sigma_t)`: Applies a Bayesian update with new observation `z` and measurement noise `sigma_t`.
 * - `getCellElevation()`: Returns the current estimated elevation.
 * - `getCellVariance()`: Returns the current estimated variance.
 *
 * Update Model:
 * - Let `ẑ` be the predicted elevation, `σ̂²` the predicted variance, and `zₜ` the current observation with noise `σₜ²`.
 *
 *   \f[
 *   Kₜ = \frac{σ̂²}{σ̂² + σₜ²}, \quad ẑₜ = ẑ + Kₜ(zₜ - ẑ), \quad σ̂²ₜ = (1 - Kₜ)σ̂²
 *   \f]
 *
 * - A minimum variance (`LOCALIZATION_VARIANCE`) is enforced to prevent overconfidence.
 *
 * Use Case:
 * - Used in both global and local elevation maps to provide temporally smoothed terrain estimates
 *   while accounting for sensor noise and elevation uncertainty.
 *
 * @credit Based on scalar Kalman filter principles, adapted for grid-based terrain mapping in robotics.
 */

#include "mapping/bayes_filter.hpp"

BayesFilter::BayesFilter()
{
    this->cellElevation = 0.0;
    this->cellVariance = 100.0;
}

void BayesFilter::updateCell(int z, float sigma_t)
{
    float z_hat = this->cellElevation;
    float sigma_hat = this->cellVariance;
    float z_t = z;
    float k_t = sigma_hat / (sigma_hat + sigma_t);
    if (this->cellElevation == 0.0)
    {
        k_t = 1.0;
    }
    this->cellElevation = z_hat + k_t * (z_t - z_hat);
    this->cellVariance = (1 - k_t) * sigma_hat;
    if (this->cellVariance < this->LOCALIZATION_VARIANCE)
    {
        this->cellVariance = this->LOCALIZATION_VARIANCE;
    }
}

float BayesFilter::getCellElevation()
{
    return this->cellElevation;
}

float BayesFilter::getCellVariance()
{
    return this->cellVariance;
}
