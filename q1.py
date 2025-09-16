import numpy as np

n, p, N = 12, 0.5, 2000
s = np.random.binomial(n, p, N)

print("Sample mean:", s.mean(), "Theoretical mean:", n*p)
print("Sample var:", s.var(ddof=1), "Theoretical var:", n*p*(1-p))

print(s)