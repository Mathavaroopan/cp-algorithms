#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right, *parent;
};

node *newnode(int data)
{
	node *ninja_node = new node;
	ninja_node->data = data;
	ninja_node->left = ninja_node->right = ninja_node->parent = nullptr;
	return ninja_node;
}

void splay(node *ninja_node)
{
	while (ninja_node->parent)
	{
		node *parent = ninja_node->parent;
		node *grandparent = parent->parent;
		if (!grandparent)
		{
			if (ninja_node == parent->left)
			{
				// Zig Rotation
				node *right = ninja_node->right;
				ninja_node->right = parent;
				parent->left = right;
			}
			else
			{
				// Zag Rotation
				node *left = ninja_node->left;
				ninja_node->left = parent;
				parent->right = left;
			}
			ninja_node->parent = nullptr;
			parent->parent = ninja_node;
		}
		else
		{
			if (ninja_node == parent->left && parent == grandparent->left)
			{
				// Zig-Zig rotation
				node *right = ninja_node->right;
				ninja_node->right = parent;
				parent->left = right;
				parent->parent = grandparent->parent;
				grandparent->parent = parent;
				if (parent->parent)
				{
					if (parent->parent->left == grandparent)
						parent->parent->left = parent;
					else
						parent->parent->right = parent;
				}
				ninja_node->parent = nullptr;
				parent->parent = ninja_node;
			}
			else if (ninja_node == parent->right && parent == grandparent->right)
			{
				// Zag-Zag rotation
				node *left = ninja_node->left;
				ninja_node->left = parent;
				parent->right = left;
				parent->parent = grandparent->parent;
				grandparent->parent = parent;
				if (parent->parent)
				{
					if (parent->parent->left == grandparent)
						parent->parent->left = parent;
					else
						parent->parent->right = parent;
				}
				ninja_node->parent = nullptr;
				parent->parent = ninja_node;
			}
			else
			{
				// Zig-Zag rotation
				if (ninja_node == parent->right)
				{
					node *left = ninja_node->left;
					ninja_node->left = parent;
					parent->right = left;
				}
				else
				{
					node *right = ninja_node->right;
					ninja_node->right = parent;
					parent->left = right;
				}
				grandparent->left = ninja_node;
				parent->parent = ninja_node;
				ninja_node->parent = grandparent;
			}
		}
	}
}

node *search(node *root, int data)
{
	if (!root)
		return nullptr;
	node *ninja_node = root;
	while (ninja_node)
	{
		if (ninja_node->data == data)
		{
			splay(ninja_node);
			return ninja_node;
		}
		else if (ninja_node->data < data)
		{
			if (!ninja_node->right)
			{
				splay(ninja_node);
				return nullptr;
			}
			ninja_node = ninja_node->right;
		}
		else
		{
			if (!ninja_node->left)
			{
				splay(ninja_node);
				return nullptr;
			}
			ninja_node = ninja_node->left;
		}
	}
}

node *insert(node *root, int data)
{
	if (!root)
		return newnode(data);
	node *ninja_node = root;
	while (ninja_node)
	{
		if (ninja_node->data == data)
		{
			splay(ninja_node);
			return ninja_node;
		}
		else if (ninja_node->data < data)
		{
			if (!ninja_node->right)
			{
				ninja_node->right = newnode(data);
				ninja_node->right->parent = ninja_node;
				splay(ninja_node->right);
				return ninja_node->right;
			}
			ninja_node = ninja_node->right;
		}
		else
		{
			if (!ninja_node->left)
			{
				ninja_node->left = newnode(data);
				ninja_node->left->parent = ninja_node;
				splay(ninja_node->left);
				return ninja_node->left;
			}
			ninja_node = ninja_node->left;
		}
	}
}

void deletenode(node *ninja_node)
{
	if (!ninja_node)
		return;
	if (!ninja_node->left && !ninja_node->right)
	{
		if (ninja_node->parent)
		{
			if (ninja_node->parent->left == ninja_node)
				ninja_node->parent->left = nullptr;
			else
				ninja_node->parent->right = nullptr;
			delete ninja_node;
		}
	}
	else if (!ninja_node->left)
	{
		if (ninja_node->parent)
		{
			if (ninja_node->parent->left == ninja_node)
				ninja_node->parent->left = ninja_node->right;
			else
				ninja_node->parent->right = ninja_node->right;
			ninja_node->right->parent = ninja_node->parent;
			delete ninja_node;
		}
		else
		{
			ninja_node->right->parent = nullptr;
			delete ninja_node;
		}
	}
	else if (!ninja_node->right)
	{
		if (ninja_node->parent)
		{
			if (ninja_node->parent->left == ninja_node)
				ninja_node->parent->left = ninja_node->left;
			else
				ninja_node->parent->right = ninja_node->left;
			ninja_node->left->parent = ninja_node->parent;
			delete ninja_node;
		}
		else
		{
			ninja_node->left->parent = nullptr;
			delete ninja_node;
		}
	}
	else
	{
		node *successor = ninja_node->right;
		while (successor->left)
		{
			successor = successor->left;
		}
		ninja_node->data = successor->data;
		deletenode(successor);
	}
}

void preorder(node *root){
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int arr[] = {72, 9, 17, 65, 82, 76, 92, 1, 52, 68};
node* root = nullptr;

for(int i : arr){
    root = insert(root, i);
}

// Print the tree in preorder traversal
preorder(root);
