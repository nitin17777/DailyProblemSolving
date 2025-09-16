'''
Create a function that computes the probability of number a in a data array 

if array is {20,20,21,21,21,22,23,26,27,27}

then compute the probaibilty of  all numbers in this array
'''

def prob_fun(a, n, k):  
    count = a.count(k)
    return round(count / n, 2)

# Data array
A = [20, 20, 21, 21, 21, 22, 23, 26, 27, 27]
N = len(A)

# Get all unique elements
unique_elements = sorted(set(A))

# Compute and print probability for each unique element
print("Probabilities of each number in the array:")
for k in unique_elements:
    prob = prob_fun(A, N, k)
    print(f"{k}: {prob}")





