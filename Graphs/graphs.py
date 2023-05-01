import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = np.genfromtxt('./data.csv', delimiter=',')

fig_arr = []
plt_arr = []
# print(data[-1])

hash_funcs_names = ["ConstHash", "LenHash", "FirstSymbHash", "SumHash", "RolHash", "RorHash", "GnuHash"]

is_graph = True
# is_graph = False

var_arr = []
avg_arr = []
std_arr = []

for i in range(len(data)):
    avg_arr.append(np.average(data[i]))
    var_arr.append(np.var(data[i]))
    std_arr.append(np.std(data[i]))
    # print('"%15s": avg=%.3lf, var=%.3lf, std=%.3lf' % (str(hash_funcs_names[i]), avg_arr[i], var_arr[i], std_arr[i]))

    # if is_graph:
    #     fig_arr.append(plt.figure(figsize = (3, 3)))
    #     plt_arr.append(fig_arr[i].add_subplot(1, 1, 1))
    #     plt_arr[i].bar(list(range(len(data[i]))), data[i])
    #     plt.title(hash_funcs_names[i])
    #     plt.ylabel("Заселённость, шт")
    #     plt.xlabel("Номер списка")

# plt.hist([data1, data2], bins=40, stacked=True)

# if is_graph:
#     plt.show()

# hash_func_names = ["SumHash", "RolHash", "RorHash", "GnuHash"]
#
# plt.bar(hash_func_names, var_arr[3:])
# plt.xlabel("Хеш-функция")
# plt.ylabel("Дисперсия")
# plt.show()
#
# plt.bar(hash_func_names, std_arr[3:])
# plt.xlabel("Хеш-функция")
# plt.ylabel("Стандартное отклонеение")
# plt.show()

optimization_times = [2.70, 1.80, 1.45]
optimization_names = ["неоптимизированная версия", "флаг -O3", "уменьшение заселённости"]

plt.bar(optimization_names, optimization_times)
plt.xlabel("Оптимизация")
plt.ylabel("Время работы программы")
plt.show()
