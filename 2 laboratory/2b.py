
def quicksort_words(lst):
    if not lst:
        return []
    random_word = lst[len(lst)//2][0]
    little = []
    larger = []
    equal = []
    for x in lst:
        if x[0] > random_word:
            larger.append(x)
        elif x[0] < random_word:
            little.append(x)
        else:
            equal.append(x)
    return quicksort_words(little) + equal + quicksort_words(larger)


in_race = [x.strip() for x in open('race.in').readlines()]
in_race = [x.split() for x in in_race]

n = in_race.pop(0)

in_race = quicksort_words(in_race)
out_race = open('race.out', 'w')


print('=== ' + in_race[0][0] + ' ===', file=out_race)
print(in_race[0][1], file=out_race)
for i in range(1, len(in_race)):
    if in_race[i-1][0] == in_race[i][0]:
        print(in_race[i][1], file=out_race)
    else:
        print('=== ' + in_race[i][0] + ' ===', file=out_race)
        print(in_race[i][1], file=out_race)

out_race.close()

