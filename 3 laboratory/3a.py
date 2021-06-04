in_isheep = [int(item) for item in open('isheap.in').read().split()]
out_isheep = open('isheap.out', 'w')
n = in_isheep[0]
for i in range(1, (n//2+2)):
    if 2 * i + 1 >= n:
        print('Yes', file=out_isheep)
        break
    if in_isheep[i] > in_isheep[2*i] or in_isheep[i] > in_isheep[2*i+1]:
        print('No', file=out_isheep)
        break
out_isheep.close()