# -*- coding: utf-8 -*-
"""Splay Trees.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1kWK14ISETR8WlxPbpRt1NRtkR6lTiWlB
"""

class Node:
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None

def newNode(key):
	return Node(key)

def rightRotate(x):
	y = x.left
	x.left = y.right
	y.right = x
	return y

def leftRotate(x):
	y = x.right
	x.right = y.left
	y.left = x
	return y

def splay(root, key):
	# Base cases: root is None or key is present at root
	if root == None or root.key == key:
		return root
	# Key lies in left subtree
	if root.key > key:
		# Key is not in tree, we are done
		if root.left == None:
			return root
		# Zig-Zig (Left Left)
		if root.left.key > key:
			# First recursively bring the key as root of left-left
			root.left.left = splay(root.left.left, key)
			# Do first rotation for root, second rotation is done after else
			root = rightRotate(root)
		elif root.left.key < key: # Zig-Zag (Left Right)
			# First recursively bring the key as root of left-right
			root.left.right = splay(root.left.right, key)
			# Do first rotation for root.left
			if root.left.right != None:
				root.left = leftRotate(root.left)
		# Do second rotation for root
		return root if root.left == None else rightRotate(root)
	else: # Key lies in right subtree
		# Key is not in tree, we are done
		if root.right == None:
			return root
		# Zig-Zag (Right Left)
		if root.right.key > key:
			# Bring the key as root of right-left
			root.right.left = splay(root.right.left, key)
			# Do first rotation for root.right
			if root.right.left != None:
				root.right = rightRotate(root.right)
		elif root.right.key < key: # Zag-Zag (Right Right)
			# Bring the key as root of right-right and do first rotation
			root.right.right = splay(root.right.right, key)
			root = leftRotate(root)
		# Do second rotation for root
		return root if root.right == None else leftRotate(root)

# Function to insert a new key k in splay tree with given root
def insert(root, k):
	# Simple Case: If tree is empty
	if (root == None):
		return newNode(k)
	root = splay(root, k)
	# If key is already present, then return
	if (root.key == k):
		return root
	# If key is not present, then insert this
	# key into the tree
	# If root's key is greater, make key as
	# root of root's left subtree
	if (root.key > k):
		n = newNode(k)
		n.right = root
		n.left = root.left
		root.left = None
		return n
	else:
		# If root's key is smaller, make key as
		# root of root's right subtree
		n = newNode(k)
		n.left = root
		n.right = root.right
		root.right = None
		return n

# A utility function to print preorder
# traversal of the tree.
# The function also prints height of every
# node
def preOrder(root):
	if (root != None):
		print(root.key, end=' ')
		preOrder(root.left)
		preOrder(root.right)

# Driver code
root = newNode(72)
root.left = newNode(9)
root.right = newNode(17)
root.left.left = newNode(65)
root.left.left.left = newNode(83)
root.left.left.left.left = newNode(76)
root = insert(root, 25)
print("Preorder traversal of the modified Splay tree is")
preOrder(root)

class Node1:
  def __init__(self, key):
    self.key = key
    self.left = None
    self.right = None

  def newNode(key):
    return Node1(key)

  def rightRotate(x): #Zig
    print("Zig...")
    y = x.left
    x.left = y.right
    y.right = x
    return y

  def leftRotate(x): #Zag
    y = x.right
    x.right = y.left
    y.left = x
    return y

  def splay(root, key):
      if root == None or root.key == key:
        return root
	  # Key lies in left subtree
      if root.key > key:
        if root.left == None:
          return root
        if root.left.key > key:
          root.left.left = splay(root.left.left, key)
          root = rightRotate(root)
        elif root.left.key < key:
          root.left.right = splay(root.left.right, key)
          if root.left.right != None:
            root.left = leftRotate(root.left)
        return root if root.left == None else rightRotate(root)
      else:
        if root.right == None:
          return root
        if root.right.key > key:
          root.right.left = splay(root.right.left, key)
          if root.right.left != None:
            root.right = rightRotate(root.right)
        elif root.right.key < key:
          root.right.right = splay(root.right.right, key)
          root = leftRotate(root)
        return root if root.right == None else leftRotate(root)

def insert(node, key):
    # If the tree is empty, return a new node
    if node is None:
        return Node1(key)

    # Otherwise, recur down the tree
    if key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)

    # Return the (unchanged) node pointer
    return node

def preOrder(root):
  if (root != None):
      print(root.key, end=' ')
      preOrder(root.left)
      preOrder(root.right)

def insert_splay(root, key):
  root = insert(root, key)
  root = splay(root, key)
  return root

def search1(root, key):
  if root == None or root.key == key:
    return root
  elif root.key>key:
    return search1(root.left,key)
  else:
    return search1(root.right,key)

def search_splay(root, key):
  print()
  print(search1(root,key).key)
  print()
  root = splay(root,key)
  return root
#parent = None
def deleteNode(root, k):
    global parent
    # Base case
    if root is None:
        return root

    # Recursive calls for ancestors of
    # node to be deleted
    if root.key > k:
        parent = root
        root.left = deleteNode(root.left, k)
        return root
    elif root.key < k:
        parent = root
        root.right = deleteNode(root.right, k)
        return root

    # We reach here when root is the node
    # to be deleted.

    # If one of the children is empty
    if root.left is None:
        temp = root.right
        del root
        return temp
    elif root.right is None:
        temp = root.left
        del root
        return temp

    # If both children exist
    else:

        succParent = root

        # Find successor
        succ = root.right
        while succ.left is not None:
            succParent = succ
            succ = succ.left

        # Delete successor.  Since successor
        # is always left child of its parent
        # we can safely make successor's right
        # right child as left of its parent.
        # If there is no succ, then assign
        # succ.right to succParent.right
        if succParent != root:
            succParent.left = succ.right
        else:
            succParent.right = succ.right

        # Copy Successor Data to root
        root.key = succ.key
        parent = root

        # Delete Successor and return root
        del succ
        return root

def delete_splay(root, key):
  root = deleteNode(root,key)
  root = splay(root, parent.key)
  return root

if __name__ == '__main__':
  root = None
  root = insert_splay(root, 72)
  preOrder(root)
  print()
  root = insert_splay(root, 9)
  preOrder(root)
  print()
  root = insert_splay(root,17)


  preOrder(root)

  print()

  root = insert_splay(root,65)

  preOrder(root)
  print()

  root = insert_splay(root,82)

  preOrder(root)
  print()
  root = insert_splay(root,76)

  preOrder(root)
  print()
  root = insert_splay(root,92)

  preOrder(root)
  print()
  root = insert_splay(root,1)

  preOrder(root)
  print()
  root = insert_splay(root,52)

  preOrder(root)
  print()
  root = insert_splay(root,68)

  preOrder(root)
  print()





  #root = delete_splay(root,50)

  #preOrder(root)
  #print()

if __name__ == '__main__':
  root = None
  root = insert(root, 5)
  root = insert(root, 4)
  root = insert(root, 3)
  root = insert(root, 4.5)
  root = insert(root, 6)
  preOrder(root)
  print()
  root = splay(root,4)
  preOrder(root)
  print()

root = None
root = insert(root, 15)
root = insert(root, 14)
root = insert(root, 12)
root = insert(root, 11)
root = insert(root, 13)
root = insert(root, 14.5)
root = insert(root, 16)
preOrder(root)
print()
root = splay(root,12)
preOrder(root)
print()

root = None
root = insert(root, 15)
root = insert(root, 14)
root = insert(root, 12)
root = insert(root, 11)
root = insert(root, 13)
root = insert(root, 14.5)
root = insert(root, 16)
preOrder(root)
print()
root = splay(root,14)
preOrder(root)
print()