import numpy as np


words = np.array(["I", "am", "Studying", "in", "BU"])


np.random.seed(44)
sample = np.random.choice(words, size = 1500,replace =True)

#Finding indices where BU occurs
bu_indices = np.where(sample[:-1] == "BU")[0]


#getting words that are just after BU
neighbours = sample[bu_indices +1]


unique, counts = np.unique(neighbours, r)




