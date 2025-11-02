/**
 * @file bayes_filter.cpp
 * @brief Implements a simple Bayesian update filter for cell elevation and variance estimation.
 *
 * This class maintains a single cell's elevation estimate and its associated uncertainty (variance).
 * Upon receiving a new measurement, it applies a Bayesian update step using a Kalman gain formulation
 * to refine the elevation estimate and reduce uncertainty, bounded by a minimum localization variance.
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
 * - Uses a Kalman gain `k_t` to blend the prior estimate (`z_hat`) and the new measurement (`z_t`).
 * - If the cell elevation is still at its initial value (0.0), the Kalman gain is forced to 1.0,
 *   making the first measurement fully overwrite the prior.
 * - The variance is reduced after each update but clamped to `LOCALIZATION_VARIANCE`.
 * - Provides getters for elevation and variance for use by other mapping modules.
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
