import matplotlib.pyplot as plt
import numpy as np
import math
import pandas as pd


data = []
s = str(input())
file = open(s, "r")
data = [map(float, line.split("\t")) for line in file]
#print(data[1])


f = pd.read_csv(s, names = ['size', 'School', 'D&C', 'Kara'])
print(f[:])

f['School'].plot()
f['D&C'].plot()
f['Kara'].plot()

plt.show()


