/*
Problem3
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
For example, given the following Node class
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
*/

struct node{
	char val;
	node *left, *right;
	node(char x)
	{
		val = x;
		left = right = NULL;
	}
};

void serialize( node* root, string &s )
{
	if(root)
	{
		s.append(val);
		serialize(root->left, s);
		serialize(root->right, s);
	}
	else
		s.append('-');
}

void deserialize(node* root, string &s)
{
	if(s[0] == '-')
	{
		s.erase(0);
		return;
	}
	root = new node(s[0]);
	s.erase(0);
	deserialize(root->left, s);
	deserialize(root->right, s);
}


