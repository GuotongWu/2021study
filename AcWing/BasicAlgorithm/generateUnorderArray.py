import numpy as np
import os
from numpy import random

number = random.randint(100)

f = open("./BasicAlgorithm/unorderArray.txt", "w")
f.write(str(number)+"\n")
for i in range(number):
    f.write(str(random.randint(100))+" ")
f.close()

f = open("./BasicAlgorithm/unorderArray.txt", "r")
print(f.read())