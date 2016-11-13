from numpy import loadtxt
import matplotlib.pyplot as plt

it, S, I, R=loadtxt("data.txt", dtype=float, unpack=True)

plt.xlabel("Number of Iterations")
plt.ylabel("Number of People")
plt.plot(it, S, label="S")
plt.plot(it, I, label="I")
plt.plot(it, R, label="R")
plt.legend()
plt.show()
