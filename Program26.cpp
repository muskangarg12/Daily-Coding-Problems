/*
Problem 26
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.
The list is very long, so making more than one pass is prohibitively expensive.
Do this in constant space and in one pass.
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
	node* next;
	node(int x)
	{
		val = x;
		next = NULL;
	}
};

void removeNode(int k, node* &root)
{
	if(root==NULL)	return;
	
	node *ref=root, *temp=root, *prev=NULL; 
	while(k)
	{
		ref=ref->next;
		k--;
	}
	
	while(ref)
	{
		ref=ref->next;
		prev=temp;
		temp=temp->next;
	}
	
	if(prev==NULL)
		root = temp->next;
	else	
		prev->next = temp->next;
}

void printList(node* root)
{
	while(root!=NULL)
	{
		cout<<root->val<<" -> ";
		root=root->next;
	}
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	node* root=new node(3);
	root->next = new node(5);
	root->next->next = new node(1);
	root->next->next->next = new node(9);
	
	printList(root);
	removeNode(4,root);
	printList(root);
}

