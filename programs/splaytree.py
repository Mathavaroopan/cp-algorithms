class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None

def splay(ninja_node):
    while ninja_node.parent:
        parent = ninja_node.parent
        grandparent = parent.parent
        if not grandparent:
            if ninja_node == parent.left:
                # Zig Rotation
                right = ninja_node.right
                ninja_node.right = parent
                parent.left = right
            else:
                # Zag Rotation
                left = ninja_node.left
                ninja_node.left = parent
                parent.right = left
            ninja_node.parent = None
            parent.parent = ninja_node
        else:
            if ninja_node == parent.left and parent == grandparent.left:
                # Zig-Zig rotation
                right = ninja_node.right
                ninja_node.right = parent
                parent.left = right
                parent.parent = grandparent.parent
                grandparent.parent = parent
                if parent.parent:
                    if parent.parent.left == grandparent:
                        parent.parent.left = parent
                    else:
                        parent.parent.right = parent
                ninja_node.parent = None
                parent.parent = ninja_node
            elif ninja_node == parent.right and parent == grandparent.right:
                # Zag-Zag rotation
                left = ninja_node.left
                ninja_node.left = parent
                parent.right = left
                parent.parent = grandparent.parent
                grandparent.parent = parent
                if parent.parent:
                    if parent.parent.left == grandparent:
                        parent.parent.left = parent
                    else:
                        parent.parent.right = parent
                ninja_node.parent = None
                parent.parent = ninja_node
            else:
                # Zig-Zag rotation
                if ninja_node == parent.right:
                    left = ninja_node.left
                    ninja_node.left = parent
                    parent.right = left
                else:
                    right = ninja_node.right
                    ninja_node.right = parent
                    parent.left = right
                grandparent.left = ninja_node
                parent.parent = ninja_node
                ninja_node.parent = grandparent

def search(root, data):
    if not root:
        return None
    ninja_node = root
    while ninja_node:
        if ninja_node.data == data:
            splay(ninja_node)
            return ninja_node
        elif ninja_node.data < data:
            if not ninja_node.right:
                splay(ninja_node)
                return None
            ninja_node = ninja_node.right
        else:
            if not ninja_node.left:
                splay(ninja_node)
                return None
            ninja_node = ninja_node.left

def insert(root, data):
    if not root:
        return Node(data)
    ninja_node = root
    while ninja_node:
        if ninja_node.data == data:
            splay(ninja_node)
            return ninja_node
        elif ninja_node.data < data:
            if not ninja_node.right:
                ninja_node.right = Node(data)
                ninja_node.right.parent = ninja_node
                splay(ninja_node.right)
                return ninja_node.right
            ninja_node = ninja_node.right
        else:
            if not ninja_node.left:
                ninja_node.left = Node(data)
                ninja_node.left.parent = ninja_node
                splay(ninja_node.left)
                return ninja_node.left
            ninja_node = ninja_node.left

def delete_node(ninja_node):
    if not ninja_node:
        return
    if not ninja_node.left and not ninja_node.right:
        if ninja_node.parent:
            if ninja_node.parent.left == ninja_node:
                ninja_node.parent.left = None
            else:
                ninja_node.parent.right = None
            del ninja_node
    elif not ninja_node.left:
        if ninja_node.parent:
            if ninja_node.parent.left == ninja_node:
                ninja_node.parent.left = ninja_node.right
            else:
                ninja_node.parent.right = ninja_node.right
            ninja_node.right.parent = ninja_node.parent
            del ninja_node
        else:
            ninja_node.right.parent = None
            del ninja_node
    elif not ninja_node.right:
        if ninja_node.parent:
            if ninja_node.parent.left == ninja_node:
                ninja_node.parent.left = ninja_node.left
            else:
                ninja_node.parent.right = ninja_node.left
            ninja_node.left.parent = ninja_node.parent
            del ninja_node
        else:
            ninja_node.left.parent = None
            del ninja_node
    else:
        successor = ninja_node.right
        while successor.left:
            successor = successor.left
        ninja_node.data = successor.data
        delete_node(successor)

def preorder(root):
    if not root:
        return
    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)

if __name__ == "__main__":
    root = None
    keys = [72, 9, 17, 65, 82, 76, 92, 1, 52, 68]

    for key in keys:
        print(key)
        root = insert(root, key)
        print("After inserting", key, "tree is:")
        preorder(root)
        print("\n")
