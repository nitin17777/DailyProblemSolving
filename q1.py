import numpy as np

# Generate 1000 random samples from Poisson(λ=3)
samples = np.random.poisson(lam=3, size=1000)

# Compute sample mean and variance
sample_mean = np.mean(samples)
sample_variance = np.var(samples, ddof=1)  # unbiased variance

print("Sample Mean:", sample_mean)
print("Sample Variance:", sample_variance)
