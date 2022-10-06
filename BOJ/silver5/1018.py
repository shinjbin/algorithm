import sys

def chess_check(board):
    white_error = 0
    for i in range(8):
        for j in range(8):
            if (i+j)%2 == 0:
                if board[i][j] != 'W':
                    white_error += 1
            else:
                if board[i][j] != 'B':
                    white_error += 1

    black_error = 0
    for i in range(8):
        for j in range(8):
            if (i+j)%2 == 0:
                if board[i][j] != 'B':
                    black_error += 1
            else:
                if board[i][j] != 'W':
                    black_error += 1

    return min(white_error, black_error)


n, m = map(int, sys.stdin.readline().split())

board = []
for _ in range(n):
    board.append(str(sys.stdin.readline())[:m])

minimum = 64
for i in range(n-7):
    for j in range(m-7):
        temp_board = board[i:i+8]
        for k in range(len(temp_board)):
            temp_board[k] = temp_board[k][j:j+8]

        temp = chess_check(temp_board)
        if temp < minimum:
            minimum = temp

print(minimum)
