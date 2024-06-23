class Node:
    def __init__(self, val, parent = None):
        self.val = val
        self.left = None
        self.right = None
        self.parent = parent
    
class Splay_Tree:
    def __init__(self):
        self.root = None
    
    def zig(self, parent):
        grandparent = parent.parent
        leftchild = parent.left
        x = leftchild.right
        parent.left = x
        if x: x.parent = parent
        leftchild.right = parent
        leftchild.parent = grandparent
        parent.parent = leftchild
        if parent == self.root: self.root = leftchild
        if grandparent:
            if grandparent.left == parent:
                grandparent.left = leftchild
            else:
                grandparent.right = leftchild
    
    def zag(self, parent):
        grandparent = parent.parent
        rightchild = parent.right
        x = rightchild.left
        parent.right = x
        if x: x.parent = parent
        rightchild.left = parent
        rightchild.parent = grandparent
        parent.parent = rightchild
        if parent == self.root: self.root = rightchild
        if grandparent:
            if grandparent.left == parent:
                grandparent.left = rightchild
            else:
                grandparent.right = rightchild
    
    def insert(self, val):
        if self.root is None:
            self.root = Node(val)
            return
        cur = self.root
        parent = None
        while cur:
            parent = cur
            if cur.val < val: cur = cur.right
            else: cur = cur.left
        new_node = Node(val, parent)
        if parent.val < val:
            parent.right = new_node
        else:
            parent.left = new_node
        self.splay(new_node)
        
    def splay(self, node):
        while node.parent:
            p = node.parent
            g = p.parent
            if not g:
                if p.left == node:
                    self.zig(p)
                else:
                    self.zag(p)
            else:
                if g.left == p and p.left == node:
                    self.zig(g)
                    self.zig(p)
                elif g.right == p and p.right == node:
                    self.zag(g)
                    self.zag(p)
                elif g.right == p and p.left == node:
                    self.zig(p)
                    self.zag(g)
                else:
                    self.zag(p)
                    self.zig(g)
                    
    def search(self, root, val):
        if not root: return
        if root.val == val:
            self.splay(root)
            return root
        elif root.val < val:
            if root.right:
                return self.search(root.right, val)
            else:
                self.splay(root)
        else:
            if root.left:
                return self.search(root.left, val)
            else:
                self.splay(root)
    
    def delete(self, root, val):
        root = self.search(root, val)
        if not root: return
        leftchild = root.left
        rightchild = root.right
        if leftchild:
            leftchild.parent = None
            root.left = None
            root.right = None
            self.root = leftchild
            while leftchild.right: leftchild = leftchild.right
            self.splay(leftchild)
            if not rightchild: return
            rightchild.parent = self.root
            self.root.right = rightchild
        else:
            rightchild.parent = None
            root.right = None
            self.root = rightchild
                
    def preorder(self, root):
        if not root: return
        print(root.val, end=" ")
        self.preorder(root.left)
        self.preorder(root.right)
        
    def inorder(self, root):
        if not root: return
        self.inorder(root.left)
        print(root.val, end=" ")
        self.inorder(root.right)
        
    def postorder(self, root):
        if not root: return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.val, end=" ")
    
    def get_root(self):
        return self.root
        
if __name__ == '__main__':
    tree = Splay_Tree()
    keys = [72, 9, 17, 65, 82, 76, 92, 1, 52, 68]

    for key in keys:
        tree.insert(key)
        print("After inserting", key, "tree is:")
        root = tree.get_root()
        tree.preorder(root)
        print("\n")
    
    tree.search(root, 9)
    root = tree.get_root()
    tree.preorder(root)
    print("\n")    
    tree.search(root, 76)
    root = tree.get_root()

    tree.preorder(root)
    print("\n")
    tree.search(root, 68)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n")
               
    tree.delete(root, 9)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 
            
    tree.delete(root, 76)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 
    
    tree.delete(root, 52)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 
        
    tree.delete(root, 82)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 
    
    tree.delete(root, 2)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 
    
    tree.delete(root, 73)
    root = tree.get_root()
    
    tree.preorder(root)
    print("\n") 