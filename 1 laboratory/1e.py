from random import choice


def quick_sort(list_):
    global max_money, min_money
    len_list = len(list_)
    if len_list <= 1:
        return list_
    else:
        random_number = choice(list_)
        smaller, larger, equal = [], [], []
        for i in range(len_list):
            if list_[i] > random_number:
                larger.append(list_[i])
            elif list_[i] < random_number:
                smaller.append(list_[i])
            else:
                equal.append(list_[i])
    return quick_sort(smaller) + equal + quick_sort(larger)


sortland_in = [float(item) for item in open('sortland.in').read().split()[1:]]
sortland_in_sorted = quick_sort(sortland_in)
sortland_out = open('sortland.out', 'w')
len_sortland_in = len(sortland_in)

for i in range(len_sortland_in):
    if sortland_in[i] == sortland_in_sorted[-1]:
        max_money = i + 1
    if sortland_in[i] == sortland_in_sorted[0]:
        min_money = i + 1
    if sortland_in[i] == sortland_in_sorted[len_sortland_in // 2]:
        average_money = i + 1
print(min_money, average_money, max_money, file=sortland_out)
sortland_out.close()
