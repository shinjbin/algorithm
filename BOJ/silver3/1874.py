import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    num_list = []
    for i in range(n):
        num_list.append(int(sys.stdin.readline()))

    length = len(num_list)

    stack = []
    result = []
    j = 0
    i = 1
    num = num_list[j]
    no = False
    while j < length-1:
        if len(stack) == 0:
            stack.append(i)
            result.append('+')
            i += 1
        elif num == stack[-1]:
            stack.pop()
            j += 1
            num = num_list[j]
            result.append('-')
        elif num > stack[-1]:
            stack.append(i)
            result.append('+')
            i += 1
        else:
            result.clear()
            result.append('NO')
            no = True
            break

    if not no:
        result.append('-')

    if n == 1:
        result = ['+', '-']

    for r in result:
        print(r)
