from numpy import loadtxt
import matplotlib.pyplot as plt


it, S, I, R=loadtxt("data.txt", dtype=float, unpack=True)

plt.xlabel("Number of Iterations")
plt.ylabel("Number of People")
plt.plot(it, S, "r--", label="S")
plt.plot(it, I, "g--", label="I")
plt.plot(it, R, "b--", label="R")
plt.legend()
plt.show()
