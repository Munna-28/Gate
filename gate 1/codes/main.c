#include <stdio.h>
#include <math.h>

int main() {
    // Given mean vector and covariance matrix
    double mu[3] = {0, 0, 0};
    double Sigma[3][3] = {{2, 2, 1},
                          {2, 5, 1},
                          {1, 1, 1}};

    // Coefficients for the linear combination
    double a[3] = {1, -2, 2};

    // Calculate mean and variance of Y = X1 - 2X2 + 2X3
    double mu_Y = 0;
    double sigma_Y_squared = 0;
    for (int i = 0; i < 3; ++i) {
        mu_Y += a[i] * mu[i];
        for (int j = 0; j < 3; ++j) {
            sigma_Y_squared += a[i] * Sigma[i][j] * a[j];
        }
    }

    // Calculate the probability using standard normal CDF
    double lower_bound = -sqrt(7.0 / 2);
    double upper_bound = sqrt(7.0 / 2);

    // Calculate cumulative probabilities using math.erf for standard normal CDF
    double lower_prob = 0.5 * (1 + erf(lower_bound / sqrt(2)));
    double upper_prob = 0.5 * (1 + erf(upper_bound / sqrt(2)));

    // Calculate the required probability
    double required_prob = upper_prob - lower_prob;

    printf("P((X1 - 2X2 + 2X3)^2 < 7/2) = %f\n", required_prob);

    return 0;
}

