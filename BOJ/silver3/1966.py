import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    imp = list(map(int, sys.stdin.readline().split()))

    result = 0
    position = m
    while True:
        if max(imp) > imp[0]:
            imp.append(imp.pop(0))
            if position != 0:
                position -= 1
            else:
                position = len(imp)-1
        else:
            imp.pop(0)
            result += 1
            if position == 0:
                break
            else:
                position -= 1

    print(result)
