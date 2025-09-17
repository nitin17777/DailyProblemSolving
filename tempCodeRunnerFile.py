import numpy as np

samples = np.random.poisson(lam=5, size=1000)

# Estimate probability of exactly 4 calls in an hour
prob_4_calls = np.mean(samples == 4)
print("Estimated P(X=4):", prob_4_calls)