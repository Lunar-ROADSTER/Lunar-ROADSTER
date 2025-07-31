/**
 * @file bayes_filter.cpp
 * @brief Implements a simple recursive Bayesian filter to update cell elevation estimates in a grid map.
 *
 * This module performs online updates to a single grid cell’s elevation and variance using a Kalman-like recursive update.
 * The estimate is updated based on new elevation observations and their measurement noise. The Bayesian update balances
 * trust in prior belief versus current sensor measurement based on their variances.
 *
 * When the elevation is first observed (elevation = 0), the Kalman gain is set to 1 to initialize the estimate directly.
 * Afterward, the filter applies the weighted update using:
 *
 * \f[
 *   \hat{z}_t = \hat{z}_{t-1} + K_t (z_t - \hat{z}_{t-1}), \quad K_t = \frac{\sigma_{t-1}^2}{\sigma_{t-1}^2 + \sigma_t^2}
 * \f]
 *
 * Variance is clamped to a minimum threshold to avoid numerical instability and overconfidence.
 *
 * @version 1.0.0
 * @date 2025-07-27
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Functions:
 * - `BayesFilter()`: Initializes the filter with a default elevation and large uncertainty.
 * - `updateCell(z, sigma_t)`: Updates elevation and variance using the current measurement `z` and its uncertainty `sigma_t`.
 * - `getCellElevation()`: Returns the current estimated elevation.
 * - `getCellVariance()`: Returns the current estimated variance.
 *
 * Parameters:
 * - `LOCALIZATION_VARIANCE`: Minimum allowed variance after update (to avoid overconfidence).
 *
 * Model:
 * - This is a 1D Bayesian filter inspired by Kalman filter equations applied to elevation estimation per cell.
 *
 * @credit Based on recursive Bayesian filtering principles used in elevation mapping and terrain modeling.
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
