import math

def normal_cdf(x):
    return 0.5 * (1 + math.erf(x / math.sqrt(2)))

n = 109
mu_claim = 3800

mean_total = n * mu_claim
sd_total = math.sqrt(n * (mu_claim**2))
threshold = 400000

z = (threshold - mean_total) / sd_total
p_total_gt = 1 - normal_cdf(z)

print("Q3 Result:")
print(f"Total mean = {mean_total:.2f}")
print(f"Total SD   = {sd_total:.2f}")
print(f"z = {z:.4f}")
print(f"P(total > 400000) ≈ {p_total_gt:.6f}")
