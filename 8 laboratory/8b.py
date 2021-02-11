input = open("input.txt")
n = int(input.readline())
table = [list(map(int, input.readline().split())) for i in range(n)]
for i in range(n):
    for j in range(n):
        if table[j][j] or table[j][i] != table[i][j]:
            open("output.txt", "w").write("NO")
            input = False
if input:
    open("output.txt", "w").write("YES")
