from random import choice

def quick_sort(list_):
    if len(list_) <= 1:
        return list_
    else:
        random_number = choice(list_)
        smaller, larger, equal = [], [], []
        for i in list_:
            if i > random_number:
                larger.append(i)
            elif i < random_number:
                smaller.append(i)
            else:
                equal.append(i)
    return quick_sort(smaller) + equal + quick_sort(larger)


sort_in = [int(item) for item in open('sort.in').read().split()]
sort_out = open('sort.out', 'w')
sort_out.write(' '.join([str(item) for item in quick_sort(sort_in[1:])]))
sort_out.close()
