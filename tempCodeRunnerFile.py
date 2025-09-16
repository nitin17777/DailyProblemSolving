import numpy as np

from math import comb


words = np.array(["I", "am", "Studying", "in", "BU"])

sample = np.random.choice(words,1500)

neigh = sample[np.where(sample[:-1] == "BU")]

vals,counts = np.unique(neigh,return_counts = True)

print("Q1", dict(zip(vals,counts/counts.sum())))





