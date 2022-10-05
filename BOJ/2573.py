from queue import Queue
import sys

N, M = map(int, sys.stdin.readline().split())

iceberg = [list(map(int, sys.stdin.readline().split())) for i in range(N)]

direction = [[-1, 0], [1, 0], [0, 1], [0, -1]]
count = [[0]*M for _ in range(N)]


def BFS(i, j):
    q = Queue()
    q.put((i, j))

    while (not q.empty()):
        currX, currY = q.get()
        visited[currX][currY] = True
        for d in direction:
            x = currX + d[0]
            y = currY + d[1]
            if 0 <= x < N and 0 <= y < M:
                if iceberg[x][y] > 0 and visited[x][y] == False:
                    visited[x][y] = True

                    q.put((x, y))
                elif iceberg[x][y] == 0:
                    count[currX][currY] += 1

    return 1


year = 0

while True:
    visited = [[False]*M for _ in range(N)]
    count = [[0]*M for _ in range(N)]
    result = []
    for i in range(N):
        for j in range(M):
            if iceberg[i][j] != 0 and visited[i][j] == False:
                result.append(BFS(i, j))

    for i in range(N):
        for j in range(M):
            iceberg[i][j] -= count[i][j]
            if iceberg[i][j] < 0:
                iceberg[i][j] = 0

    if len(result) == 0:
        print(0)
        break

    if len(result) > 1:
        print(year)
        break

    year += 1
