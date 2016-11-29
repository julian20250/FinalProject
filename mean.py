import numpy as np
import matplotlib.pyplot as plt
strings=["data"]
for x in range(1,6):
    strings.append(strings[0]+str(x))
for x in range(len(strings)):
    strings[x]=strings[x]+".txt"
datos=[]
for x in strings:
    datos.append(np.transpose(np.loadtxt(x,dtype=int, usecols=[1,2,3])))
mean1=[(x+y+z+w+a+b)/6. for x,y,z,w,a,b in zip(datos[0][0], datos[1][0],datos[2][0],
                                              datos[3][0],datos[4][0],datos[5][0])]
mean2=[(x+y+z+w+a+b)/6. for x,y,z,w,a,b in zip(datos[0][1], datos[1][1],datos[2][1],
                                               datos[3][1],datos[4][1],datos[5][1])]
mean3=[(x+y+z+w+a+b)/6. for x,y,z,w,a,b in zip(datos[0][2], datos[1][2],datos[2][2],
                                               datos[3][2],datos[4][2],datos[5][2])]
plt.plot(range(51), mean1)
plt.plot(range(51), mean2)
plt.plot(range(51), mean3)
plt.show()
