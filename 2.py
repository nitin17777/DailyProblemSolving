import math

def normal_cdf(x, mean, sd):
    z = (x - mean) / (sd * math.sqrt(2))
    return 0.5 * (1 + math.erf(z))

mean, sd = 70, 10

p1 = 1 - normal_cdf(80, mean, sd)                        
p2 = normal_cdf(75, mean, sd) - normal_cdf(60, mean, sd) 
p3 = 1 - normal_cdf(85, mean, sd)                        

expstd = 200 * p3 

print("P(X > 80) =", p1)
print("P(60 <= X <= 75) =", p2)
print("Expected students above 85 out of 200 =", expstd)