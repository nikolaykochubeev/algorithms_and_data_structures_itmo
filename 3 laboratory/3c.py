input_array = open('radixsort.in')
output_array = open('radixsort.out', 'w')
n, m, k = map(int, input_array.readline().split())
string = [[] for i in range(26)]
array = [input_array.readline().strip() for item in open('radixsort.in')]

for i in range(k):
    [string[j].clear() for j in range(26)]
    for j in range(n):
        symbol = ord(array[j][m - i - 1]) - ord('a')
        string[symbol].append(array[j])
    array.clear()
    for j in range(26):
        if len(string[j]):
            i = 0
            while i < len(string[j]):
                array.append(string[j][i])
                i += 1

print(*array, file=output_array, sep='\n')
output_array.close()
