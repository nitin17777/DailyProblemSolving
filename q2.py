import numpy as np

x = np.array([0,1,2,3,4,5,6])
f = np.array([4,7,11,14,13,8,3])
n = f.sum()

# probabilities
p = f / n

# mean
mean = np.sum(x * p)

# variance
variance = np.sum(x**2 * p) - mean**2

# probability of at least 4
prob_at_least_4 = p[x >= 4].sum()

print("Mean:", mean)
print("Variance:", variance)
print("P(X >= 4):", prob_at_least_4)
