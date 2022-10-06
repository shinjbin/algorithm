import sys


def check(x, li):
    result = 0
    for i in li:
        result += i // x

    return result


k, n = map(int, sys.stdin.readline().split())

k_list = []
for i in range(k):
    k_list.append(int(sys.stdin.readline()))

mi = 1
ma = max(k_list)
output = int()


while(mi <= ma):
    temp = (mi + ma) // 2
    r = check(temp, k_list)
    if r >= n:
        mi = temp+1
    else:
        ma = temp-1

print(ma)