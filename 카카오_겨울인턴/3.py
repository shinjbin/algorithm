#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'solution' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY box as parameter.
#

def solution(box):
    # Write your code here
    Sum = 0
    for b in box:
        Sum += b
    
    answer = 0
    
    for i in reversed(range(1, len(box))):
        Avg = Sum // (i+1)
        if Sum % (i+1) != 0:
            Avg += 1
            
        if box[i] > Avg:
            box[i-1] += box[i] - Avg
            box[i] = Avg
        
        Sum -= box[i]
        answer = max(answer, box[i])
    
    answer = max(answer, box[0])
        
    return answer
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    box_count = int(input().strip())

    box = []

    for _ in range(box_count):
        box_item = int(input().strip())
        box.append(box_item)

    result = solution(box)

    fptr.write(str(result) + '\n')

    fptr.close()
