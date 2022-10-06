import sys

l = int(sys.stdin.readline())

s = list(map(int, sys.stdin.readline().split()))

n = int(sys.stdin.readline())

s.append(0)
s.sort()

end = s[0]
start = s[0]
for i in range(len(s)):
    if s[i] > n:
        end = s[i] - 1
        start = s[i-1] + 1
        break

if n in s:
    result = 0
else:
    result = (n - start) * (end - n + 1) + (end - n)
print(result)