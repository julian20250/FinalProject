import numpy as np
import matplotlib.pyplot as plt


pInm, S=np.loadtxt("outputPinm.txt", dtype=float, unpack=True)
S, pInm=list(S),list(pInm)
while True:
    try:
        count=S.index(0)
        S.pop(count)
        pInm.pop(count)
    except ValueError:
        break
        
S, pInm=np.array(S),np.array(pInm)
log_S= np.log(S)
z=np.polyfit(pInm, log_S,1)
print(z[0])
p=np.poly1d(z)
plt.xlabel(r"$P_{inm}$", fontsize=14)
plt.ylabel(r"Final $S$")
plt.semilogy(pInm, S, "r--", marker="o", label="Simulated plot")
plt.semilogy(pInm, np.e**p(pInm), "g--", label="Polynomial Fit")
plt.legend()
plt.show()
