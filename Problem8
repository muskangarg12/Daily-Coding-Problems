/*
Problem 8
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees.
For example, the following tree has 5 unival subtrees:
   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
#define s    second
#define ll   long long
#define vi vector< int >
#define vl vector< ll >
#define rep(i,j,n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define all(v) v.begin(), v.end()
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define Max  INT_MAX
#define Min  INT_MIN
#define mod  1000000007
using namespace std;

struct node{
	int val;
	node *left, *right;
	
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};

pair< int , bool > countUnival(node* root)
{
	if(root == NULL)
		return {0,1};
	
	pair< int , bool > leftcount, rightcount;
	leftcount = countUnival(root->left);
	rightcount = countUnival(root->right);
	
	int ans = leftcount.f+rightcount.f;
	
	bool univalCurr=1;
	if(!leftcount.s || !rightcount.s)
		univalCurr=0;
	if((root->left!=NULL && root->left->val != root->val) || (root->right!=NULL && root->right->val != root->val))
		univalCurr=0;
		
	if(univalCurr)
		return {(leftcount.f+rightcount.f+1),1};
	else
		return {(leftcount.f+rightcount.f),0};			
}

node* createTree()
{
	int val;
	cin>>val;
	if(val!=-1)
	{
		node *root = new node(val);
		cout<<"Enter Left : ";
		root->left = createTree();
		cout<<"Enter right : ";
		root->right = createTree();
		return root;
	}
	return NULL;
}

int main()
{
	node *root = createTree();
	
	pair< int, bool > ans = countUnival(root);
	cout<<ans.f<<"\n";
}

