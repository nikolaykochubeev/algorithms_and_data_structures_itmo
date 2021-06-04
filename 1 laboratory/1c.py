turtle_in = open("turtle.in")
turtle_out = open("turtle.out", "w")
w, h = map(int, turtle_in.readline().split())
m, n = 0, 0
tabl = [list(map(int, turtle_in.readline().split())) for i in range(w)]
max_values = [[0] * h for j in range(w)]
for i in range(w - 1, -1, -1):
    for j in range(h):
        if i == w - 1 and j == 0:
            max_values[w - 1][0] = tabl[w - 1][0]
        elif i == w - 1:
            max_values[w - 1][j] = max_values[w - 1][j - 1] + tabl[w - 1][j]
        elif j == 0:
            max_values[i][0] = max_values[i + 1][0] + tabl[i][0]
        else:
            max_values[i][j] = max(max_values[i + 1][j], max_values[i][j - 1]) + tabl[i][j]
print(max_values[0][h - 1], file=turtle_out)
turtle_out.close()
