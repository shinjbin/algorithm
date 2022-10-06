import sys

if __name__ == "__main__":

    t = int(sys.stdin.readline())

    for _ in range(t):
        zeros = [1, 0]
        ones = [0, 1]
        n = int(sys.stdin.readline())
        for i in range(2, n+1):
            zeros.append(zeros[i-1]+zeros[i-2])
            ones.append(ones[i-1]+ones[i-2])

        print(zeros[n], ones[n])
