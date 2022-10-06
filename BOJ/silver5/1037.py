import sys

n = int(sys.stdin.readline())

measure = list(map(int, sys.stdin.readline().split()))

print(min(measure)*max(measure))

