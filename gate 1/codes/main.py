import math

# Given mean vector and covariance matrix
mu = [0, 0, 0]
Sigma = [[2, 2, 1],
         [2, 5, 1],
         [1, 1, 1]]

# Coefficients for the linear combination
a = [1, -2, 2]

# Calculate mean and variance of Y = X1 - 2X2 + 2X3
mu_Y = sum(a[i] * mu[i] for i in range(3))
sigma_Y_squared = sum(sum(a[i] * Sigma[i][j] * a[j] for i in range(3)) for j in range(3))

# Calculate the probability using standard normal CDF
lower_bound = -math.sqrt(7/2)
upper_bound = math.sqrt(7/2)

# Calculate cumulative probabilities using math.erf for standard normal CDF
lower_prob = 0.5 * (1 + math.erf(lower_bound / math.sqrt(2)))
upper_prob = 0.5 * (1 + math.erf(upper_bound / math.sqrt(2)))

# Calculate the required probability
required_prob = upper_prob - lower_prob

print("P((X1 - 2X2 + 2X3)^2 < 7/2) =", required_prob)


