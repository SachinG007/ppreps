#!/bin/python

import math
import os
import random
import re
import sys
chaos = 0
# Complete the minimumBribes function below.
def minimumBribes(q):
    chaos = 0
    ans = 0
    swapped = 0
    
    for i in range(len(q)):
        if ((q[i] - (i+1))>2):
            chaos = 1
            
    for i in range(len(q) - 1):
        for j in range(len(q) - 1):
            if(q[j]>q[j+1]):
                temp = q[j]
                q[j] = q[j+1]
                q[j+1] = temp
                ans = ans + 1
                swapped = 1
                
        if swapped==1:
            swapped = 0
        else:
            break
                
    if (chaos == 1):
        print("Too chaotic")
    else:
        print ans
                
            
        
    

if __name__ == '__main__':
    t = int(raw_input())

    for t_itr in xrange(t):
        global chaos
        chaos = 0
        n = int(raw_input())

        queue = map(int, raw_input().rstrip().split())
        # global chaos
        minimumBribes(queue)
        # if(chaos==0):
        #     print(ans)
        # else:
        #     print("Too chaotic")
