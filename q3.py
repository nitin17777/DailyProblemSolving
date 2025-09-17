import numpy as np

p = 0.25

# (a) Simulate 50 games
attempts = np.random.geometric(p, size=50)
print("Attempts for 50 games:", attempts)

# (b) Compute sample mean
sample_mean = np.mean(attempts)

# Theoretical expected value
theoretical_mean = 1 / p

print("Sample Mean Attempts:", sample_mean)
print("Theoretical Expected Attempts:", theoretical_mean)
