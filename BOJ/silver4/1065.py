import sys


def hansu(x):
    if x < 100:
        return x
    else:
        count = 0
        for i in range(100, x+1):
            hund = i // 100
            ten = (i%100) // 10
            one = (i%100) % 10
            if (hund - ten) == (ten-one):
                count += 1

        return (count+99)

n = int(sys.stdin.readline())
print(hansu(n))