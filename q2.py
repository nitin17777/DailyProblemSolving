import numpy as np

# (a) Simulate number of calls in 12 hours (Poisson with λ = 60)
calls_12_hours = np.random.poisson(lam=60)
print("Simulated calls in 12 hours:", calls_12_hours)

# (b) Generate 1000 random samples for 1 hour (Poisson with λ = 5)
samples = np.random.poisson(lam=5, size=1000)

# Estimate probability of exactly 4 calls in an hour
prob_4_calls = np.mean(samples == 4)
print("Estimated P(X=4):", prob_4_calls)

# (c) Compare sample mean and variance with theoretical values
sample_mean = np.mean(samples)
sample_variance = np.var(samples, ddof=1)  # unbiased
theoretical_mean = 5
theoretical_variance = 5

print("Sample Mean:", sample_mean)
print("Sample Variance:", sample_variance)
print("Theoretical Mean:", theoretical_mean)
print("Theoretical Variance:", theoretical_variance)
