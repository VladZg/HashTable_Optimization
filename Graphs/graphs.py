import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = np.genfromtxt('./data.csv', delimiter=',')

fig_arr = []
plt_arr = []
# print(data[-1])

for i in range(len(data)-1):
    fig_arr.append(plt.figure(figsize = (3, 3)))
    plt_arr.append(fig_arr[i].add_subplot(1, 1, 1))
    plt_arr[i].bar(list(range(len(data[i]))), data[i])

plt.show()
