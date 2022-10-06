import sys

n = sys.stdin.readline()
a = set(sys.stdin.readline().split())

m = sys.stdin.readline()
nums = sys.stdin.readline().split()

for num in nums:
    print(1) if num in a else print(0)