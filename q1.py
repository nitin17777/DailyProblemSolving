import numpy as np

np.random.seed(42)

n = 40       # sample size
sims = 1000  # number of samples

# 1) Normal(18, 20)
norm_samples = np.random.normal(18, 20, size=(sims, n))
norm_means = norm_samples.mean(axis=1)

# 2) Poisson(10)
pois_samples = np.random.poisson(10, size=(sims, n))
pois_means = pois_samples.mean(axis=1)

# 3) Exponential(rate=20 => mean=1/20)
exp_samples = np.random.exponential(scale=1/20, size=(sims, n))
exp_means = exp_samples.mean(axis=1)

print("Q1 Results:")
print(f"Normal: mean={norm_means.mean():.4f}, sd={norm_means.std(ddof=1):.4f}")
print(f"Poisson: mean={pois_means.mean():.4f}, sd={pois_means.std(ddof=1):.4f}")
print(f"Exponential: mean={exp_means.mean():.6f}, sd={exp_means.std(ddof=1):.6f}")
