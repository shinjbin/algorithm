import sys
import math

n = int(sys.stdin.readline())

li = [x for x in range(n+1)]

for i in range(1,n+1):
    for j in range(1,i):
        if j*j > i:
            break
        if li[i] > li[i-j*j] + 1:
            li[i] = li[i-j*j] + 1

print(li[n])


