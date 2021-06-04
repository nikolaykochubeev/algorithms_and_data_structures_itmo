array = [int(item) for item in open('sort.in').read().split()]
sort_out = open('sort.out', 'w')


def heapify(array, heap_size, root_index):
    largest = root_index
    left = (2 * root_index) + 1
    right = (2 * root_index) + 2
    if left < heap_size and array[left] > array[largest]:
        largest = left
    if right < heap_size and array[right] > array[largest]:
        largest = right
    if largest != root_index:
        array[root_index], array[largest] = array[largest], array[root_index]
        heapify(array, heap_size, largest)


def heap_sort(array, len_array):
    for i in range(len_array, -1, -1):
        heapify(array, len_array, i)
    for i in range(len_array - 1, 0, -1):
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)


len_array = array.pop(0)
heap_sort(array, len_array)
print(*array, file=sort_out)
