import numpy as np
x=np.array([
    [2,9,1],
    [9,3,1],
    [8,3,1],
    [8,8,1],
    [2,1,1],
    [8,4,1],
    [4,3,1],
    [1,8,1],
    [3,3,1],
    [5,3,1]
])
y=np.array([
    [290],
    [1054],
    [944],
    [964],
    [246],
    [948],
    [488],
    [167],
    [370],
    [598]
])
z=np.array([
    [2,0,0],
    [0,2,0],
    [0,0,2]
])
x=np.matrix(x)
y=np.matrix(y)
z=np.matrix(z)
temp=(z+x.T*x).I*x.T*y
print(temp)