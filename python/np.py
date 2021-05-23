import numpy as np

x = np.array([[3,1,4], [1,5,9], [2,6,5]])
f = np.exp(x)
print(f)

n = 10
def computeEx(x, k):
    if k == 1:
        return x
    else:
        return np.dot(computeEx(x, k-1), x)

def sum_x(n):
    denominator = 1
    f_pred = np.ones(x.shape)
    for i in range(n):
        f_pred += computeEx(x,(i+1))/denominator
        denominator /= (i+1) 
    return f_pred

for i in range(n):
    print(sum_x(i))