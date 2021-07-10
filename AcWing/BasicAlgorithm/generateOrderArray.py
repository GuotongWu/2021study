import numpy as np
from numpy import random

num = random.randint(50,100)
unorder = np.sort(random.randint(1,100,(num)))

f = open("./orderArray.txt", "w")
f.write(str(num)+"\n")
for i in range(num):
    f.write(str(unorder[i])+" ")