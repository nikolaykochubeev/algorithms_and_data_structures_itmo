class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()


stack_array = Stack()
input_array = [item for item in open('stack.in').read().split()]
output_file = open('stack.out', 'w')

for i in range(1, len(input_array)):
    if input_array[i] == '-':
        print(stack_array.pop(), file=output_file)
    if input_array[i] == '+':
        stack_array.push(int(input_array[i + 1]))