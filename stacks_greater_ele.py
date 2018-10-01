#!/bin/python

import math
import os
import numpy as np
import random
import re
import sys
chaos = 0
ans = np.zeros((1001,1))
# Complete the minimumBribes function below.
def next_greater(q):
    global ans
    s = []
    crnt_ele = 0;
    ele = 0;
    
    for i in range(len(q)):
        crnt_ele = q[i]
        
        if (len(s)!=0):
            
            ele = s.pop()
            
            while ele < crnt_ele:
                # print(ele,crnt_ele)
                ans[ele] = crnt_ele
                if (len(s) == 0):
                    break
                ele = s.pop()
                
            if ele>crnt_ele:
                s.append(ele)
                
        s.append(crnt_ele)
        
    while(len(s) !=0):
        answ = -1
        ele = s.pop()
        # print(ele,answ)
        ans[ele] = answ




if __name__ == '__main__':
    t = int(input())
    # global a

    for t_itr in range(t):

        n = int(input())

        queue = list(map(int, input().split()))
        # global chaos
        next_greater(queue)
        for i in queue:
            i = int(i)
            k = ans[i]
            k = int(k)
            print(k, end = ' ')
        print(" ")
