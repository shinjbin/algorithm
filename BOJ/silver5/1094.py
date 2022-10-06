import sys

n = int(sys.stdin.readline())
result = 0

while (n > 0):
    if n % 2 == 1:
        result += 1

    n = n // 2

print(result)