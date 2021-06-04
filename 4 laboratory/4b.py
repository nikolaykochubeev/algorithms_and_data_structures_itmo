class Queue:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop(0)


Queue_array = Queue()
input_array = [item for item in open('queue.in').read().split()]
output_file = open('queue.out', 'w')

for i in range(1, len(input_array)):
    if input_array[i] == '-':
        print(Queue_array.pop(), file=output_file)
    if input_array[i] == '+':
        Queue_array.push(int(input_array[i + 1]))