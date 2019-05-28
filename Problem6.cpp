/*
Problem 6
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
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

struct xnode {
	int val;
	xnode *both;
	
	xnode(int v)
	{
		val = v;
		both = NULL;
	}
};

xnode* XOR(xnode* a, xnode* b)
{
	return (xnode*)((ll)a ^ (ll)b);
}

void add(xnode* &root, int x)
{
	if(root==NULL)
	{
		xnode* temp = new xnode(x);
		root = temp;
	}
	else
	{
		xnode *prev=NULL, *next=NULL, *temp=root;
		while(temp)
		{
			next = XOR(temp->both,prev);
			prev = temp;
			temp = next;
		}
		
		temp = new xnode(x);
		temp->both = XOR(temp->both, prev);
		prev->both = XOR(prev->both, temp); 
	}
}

int get(xnode* root, int idx)
{
	int i=0;
	xnode *prev=NULL, *next=NULL, *temp=root;
	while(temp)
	{
		if(i==idx)
			return temp->val;
		next = XOR(temp->both,prev);
		prev = temp;
		temp = next;
		i++;
	}
	
	return -1;	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	xnode* root = NULL;
	
	while(1)
	{
		int x;
		printf("1. Press 1 to add new node. \n2. Press 2 to get element at index i. \n3. Press 3 to exit.\n");
		scanf("%d",&x);
		bool flag=0;
		switch(x)
		{
			case 1:{
				int y; cin>>y;
				add(root,y);
				break;
			}
			case 2:{
				int y; cin>>y;
				printf("Value at i is : %d \n", get(root, y));
				break;
			}
			default:{
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
}
