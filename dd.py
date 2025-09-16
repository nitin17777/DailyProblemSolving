# Take seed input
N = int(input("Enter a seed value: "))  # Example input: 2

# Import NumPy
import numpy as np

# Set seed
np.random.seed(N)

# Generate 1500 random integers in range [90, 100)
random_list = np.random.randint(90, 100, 1500)

# Count frequency of each number
frequency = {}

for item in random_list:
    if item in frequency:
        frequency[item] += 1
    else:
        frequency[item] = 1

# Print frequency dictionary
print("Frequency of numbers between 90 and 99:\n")
for key in sorted(frequency):
    print(f"{key}: {frequency[key]}")

