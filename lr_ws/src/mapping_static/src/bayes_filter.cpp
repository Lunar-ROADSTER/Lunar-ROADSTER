/**
 * @file bayes_filter.cpp
 * @brief Implements a simple Bayesian update filter for per-cell elevation and variance estimation in elevation maps.
 *
 * This class maintains an elevation estimate and variance for a single grid cell. When a new
 * measurement is received, it applies a Bayesian update step (Kalman gain style) to refine the
 * elevation estimate and reduce uncertainty. Variance is bounded below by a configurable
 * `LOCALIZATION_VARIANCE` to prevent overconfidence.
 *
 * @version 1.0.0
 * @date 2025-08-09
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - None
 *
 * Publishers:
 * - None
 *
 * Services:
 * - None
 *
 * Parameters:
 * - LOCALIZATION_VARIANCE: [float] Minimum allowable variance after an update.
 *
 * Notes:
 * - Initializes cell elevation to 0.0 and variance to 100.0.
 * - Kalman gain `k_t` is computed as `sigma_hat / (sigma_hat + sigma_t)`.
 * - For the first measurement (cell elevation = 0.0), `k_t` is forced to 1.0 so the measurement fully replaces the estimate.
 * - Variance is reduced after each update but never goes below `LOCALIZATION_VARIANCE`.
 * - `getCellElevation()` and `getCellVariance()` provide read-only access to the current state.
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
