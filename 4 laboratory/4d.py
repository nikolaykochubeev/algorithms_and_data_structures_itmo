output_file = open('postfix.out', 'w')
stack = []
for element in [item for item in open('postfix.in').read().split()]:
    if element in '+-*':
        a, b = stack[-2], stack[-1]
        stack.pop()
        stack.pop()
        result = eval('a {} b'.format(element))
        stack.append(result)
    else:
        stack.append(int(element))
print(stack[0], file=output_file)
