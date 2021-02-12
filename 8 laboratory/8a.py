input = open("input.txt").readlines()
output = open("output.txt", "w")
n, m = int(input[0][0]), int(input[0][2])
table = [list(map(int, input[i].split())) for i in range(int(len(input)))][1:]
matrix = [[0] * n for i in range(n)]
for i in range(m):
    matrix[table[i][0] - 1][table[i][1] - 1] = 1
[print(*string, sep=' ', file=output) for string in matrix]
