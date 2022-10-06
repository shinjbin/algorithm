import sys

n = int(sys.stdin.readline())

cal = [0] * (n+1)

for i in range(2, n+1):
    if i % 3 == 0 and i % 2 == 0:
        cal[i] = min(cal[i-1]+1, cal[i//3]+1, cal[i//2]+1)
    elif i % 3 == 0 and i % 2 != 0:
        cal[i] = min(cal[i-1]+1, cal[i//3]+1)
    elif i % 3 != 0 and i % 2 == 0:
        cal[i] = min(cal[i-1]+1, cal[i//2]+1)
    else:
        cal[i] = cal[i-1]+1

print(cal[n])