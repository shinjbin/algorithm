import sys

n = int(sys.stdin.readline())
lopes = []
for i in range(n):
    lopes.append(int(sys.stdin.readline()))

lopes.sort(reverse=True)

max_poss = 0
poss = 0
for i in range(len(lopes)):
    poss = lopes[i] * (i+1)
    if poss > max_poss:
        max_poss = poss

print(max_poss)