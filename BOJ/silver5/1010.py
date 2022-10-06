import sys
from math import factorial


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        n, m = map(int, sys.stdin.readline().split())

        result = factorial(m) // (factorial(n) * factorial(m-n))
        print(result)
