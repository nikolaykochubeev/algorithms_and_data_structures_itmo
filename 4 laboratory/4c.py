input_array = [item for item in open('brackets.in').read().split()]
output_file = open('brackets.out', 'w')


def is_correct_brackets(str):
    while '()' in str or '[]' in str or '{}' in str:
        str = str.replace('()', '')
        str = str.replace('[]', '')
        str = str.replace('{}', '')
    return not str


for i in range(len(input_array)):
    if is_correct_brackets(input_array[i]):
        print('YES', file=output_file)
    else:
        print('NO', file=output_file)
output_file.close()
