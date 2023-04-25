import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = np.genfromtxt('./data.csv', delimiter=',')

fig_arr = []
plt_arr = []
# print(data[-1])

hash_funcs_names = ["ConstHash", "LenHash", "FirstSymbHash", "SumHash", "RolHash", "RorHash", "MyHash", "GnuHash"]

is_graph = True
# is_graph = False

for i in range(len(data)):
    print('"%15s": avg=%.3lf, var=%.3lf, std=%.3lf' % (str(hash_funcs_names[i]), np.average(data[i]), np.var(data[i]), np.std(data[i])))

    if is_graph:
        fig_arr.append(plt.figure(figsize = (3, 3)))
        plt_arr.append(fig_arr[i].add_subplot(1, 1, 1))
        plt_arr[i].bar(list(range(len(data[i]))), data[i])
        plt.title(hash_funcs_names[i])
        plt.ylabel("Заселённость, шт")
        plt.xlabel("Номер списка")

# plt.hist([data1, data2], bins=40, stacked=True)

if is_graph: plt.show()
