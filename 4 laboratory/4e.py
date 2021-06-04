def binSearchLeft(array, element):
    l = -1
    r = len(array)
    while r - l > 1:
        mid = (l + r) // 2
        if array[mid] < element:
            l = mid
        else:
            r = mid
    if r >= len(array):
        r -= 1
    if array[r] == element:
        return r + 1
    else:
        return -1


def binSearchRight(array, element):
    l = -1
    r = len(array)
    while r - l > 1:
        mid = (l + r) // 2
        if array[mid] > element:
            r = mid
        else:
            l = mid
    if array[l] == element:
        return l + 1
    else:
        return -1


in_array = [item.split() for item in [item.strip() for item in open('binsearch.in').readlines()]]
output_array = open('binsearch.out', 'w')

in_array[1] = [int(item) for item in in_array[1]]
for i in range(int(in_array[-2][0])):
    print(*[binSearchLeft(in_array[1], int(in_array[-1][i])), binSearchRight(in_array[1], int(in_array[-1][i]))],
          file=output_array)
