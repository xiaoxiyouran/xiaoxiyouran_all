#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: gini.encropy.py
message: notes for liaoxuefeng in learning pyhon 3.7
from: https://blog.csdn.net/sinat_22594309/article/details/59090895
'''

import numpy as np
from matplotlib import pyplot as plt
p = np.linspace(0.001, 1, 100, endpoint=False)
gini = 2 * p * (1-p)
ent= - (p * np.log2(p) + (1-p) * np.log2(1-p))/2
error= 1 - np.max(np.vstack((p,1 - p)), 0)
plt.plot(p, gini,'r-',label='Gini')
plt.plot(p, ent,'b-', label='Entropy')
plt.plot(p,error,'g-',label='Error')
plt.legend(loc='upper right')
plt.show()