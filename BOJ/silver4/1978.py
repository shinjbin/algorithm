import math
import sys


def prime(x):
    if x == 1:
        return False
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True


n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

result = 0
for num in nums:
    if prime(num):
        result += 1

print(result)