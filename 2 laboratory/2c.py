in_inversions = open("inversions.in")
out_inversions = open("inversions.out", "w")
c = open('inversions.in')
in_inversions = [int(item) for item in open('inversions.in').read().split()]


def mergesort(array, n):
    array_sorted = [0] * n
    return mergesort_counting_inversions(array, array_sorted, 0, n - 1)


def mergesort_counting_inversions(array, array_sorted, left, right):
    count_inversions = 0
    if left < right:
        mid = (left + right) // 2
        count_inversions += mergesort_counting_inversions(array, array_sorted, left, mid)
        count_inversions += mergesort_counting_inversions(array, array_sorted, mid + 1, right)
        count_inversions += merge(array, array_sorted, left, mid, right)
    return count_inversions


def merge(array, array_sorted, left, mid, right):
    i = left
    j = mid + 1
    k = left
    inv_count = 0

    while i <= mid and j <= right:
        if array[i] <= array[j]:
            array_sorted[k] = array[i]
            k += 1
            i += 1
        else:
            array_sorted[k] = array[j]
            inv_count += (mid - i + 1)
            k += 1
            j += 1
    while i <= mid:
        array_sorted[k] = array[i]
        k += 1
        i += 1
    while j <= right:
        array_sorted[k] = array[j]
        k += 1
        j += 1
    for i in range(left, right + 1):
        array[i] = array_sorted[i]
    return inv_count


count_inversions = mergesort(in_inversions[1:], in_inversions[0])

print(count_inversions, file=out_inversions)
out_inversions.close()
c.close()