import math

def binomial_pmf(n, k, p):
    """Compute Binomial PMF: P(X = k) for given n, k, and p."""
    if k < 0 or k > n:
        return 0.0
    comb = math.factorial(n) // (math.factorial(k) * math.factorial(n - k))
    return comb * (p ** k) * ((1 - p) ** (n - k))

# Example usage:
n, p = 12, 0.5
for k in range(0, 5):
    print(f"P(X={k}) = {binomial_pmf(n, k, p):.5f}")
