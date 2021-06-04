class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key



def insert(node, key):
    if node is None:
        return Node(key)
    else:
        if node.value == key:
            return node
        elif node.value < key:
            node.right = insert(node.right, key)
        else:
            node.left = insert(node.left, key)
    return node


def min_in_node(node):
    while node.left is not None:
        node = node.left
    return node


def delete(node, key):
    if node is None:
        return node
    if key < node.value:
        node.left = delete(node.left, key)
    elif key > node.value:
        node.right = delete(node.right, key)
    else:
        if node.left is None:
            temp = node.right
            return temp

        elif node.right is None:
            temp = node.left
            return temp
        temp = min_in_node(node.right)
        node.value = temp.value
        node.right = delete(node.right, temp.value)

    return node


def exists(node, target):
    if node is None:
        return 'false'
    else:
        if target == node.value:
            return 'true'
        else:
            if target < node.value:
                return exists(node.left, target)
            else:
                return exists(node.right, target)


def prev(root, key):
    global k
    global temp
    if root is not None:
        prev(root.left, key)
        if key > root.value > temp:
            temp = root.value
            k = 1
        prev(root.right, key)
        if k:
            return temp
        else:
            return 'none'

def next(root, key):
    global k
    global temp
    if root is not None:
        next(root.left, key)
        if key < root.value < temp:
            temp = root.value
            k = 1
        next(root.right, key)
        if k:
            return temp
        else:
            return 'none'


input = [j.split() for j in [x.strip() for x in open('bstsimple.in').readlines()]]
out = open('bstsimple.out', 'w')

tree = Node(10000000000000001)

for i in input:
    if i[0] == 'insert':
        insert(tree, int(i[1]))
    elif i[0] == 'exists':
        print(exists(tree, int(i[1])), file=out)
    elif i[0] == 'delete':
        delete(tree, int(i[1]))
    elif i[0] == 'next':
        temp = 10000000000000
        k = 0
        print(next(tree, int(i[1])), file=out)
    elif i[0] == 'prev':
        k=0
        temp = -10000000000000
        print(prev(tree, int(i[1])), file=out)
