from numpy import loadtxt
import matplotlib.pyplot as plt


pInm, S=loadtxt("outputPinm.txt", dtype=float, unpack=True)

plt.xlabel(r"$P_{inm}$", fontsize=14)
plt.ylabel(r"Final $S$")
plt.plot(pInm, S, "r--", marker="o")
plt.legend()
plt.show()
