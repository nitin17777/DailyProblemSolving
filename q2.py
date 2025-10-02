import math

# Helper: Normal CDF using error function
def normal_cdf(x):
    return 0.5 * (1 + math.erf(x / math.sqrt(2)))

mu, sigma, n = 75, 25, 110
se = sigma / math.sqrt(n)
z = (82 - mu) / se
p_gt_82 = 1 - normal_cdf(z)

print("Q2 Result:")
print(f"Standard error = {se:.4f}")
print(f"z = {z:.4f}")
print(f"P(sample mean > 82) = {p_gt_82:.6f}")
