import sys

if __name__ == "__main__":
    string = str(sys.stdin.readline().rstrip())
    m = int(sys.stdin.readline())
    str1 = list(string)
    str2 = []

    for _ in range(m):
        opt = str(sys.stdin.readline())
        if opt[0] == "L":
            if str1:
                str2.append(str1.pop())
        elif opt[0] == 'D':
            if str2:
                str1.append(str2.pop())
        elif opt[0] == 'B':
            if str1:
                str1.pop()
        elif opt[0] == 'P':
            str1.append(opt[2])

    str1.extend(reversed(str2))
    print(''.join(str1))
