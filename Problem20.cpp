/*
Problem 20
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
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

int findNode(node* l1, node* l2)
{
	node* temp=l1;
	int len=1;
	while(temp->next)
	{
		temp=temp->next;
		len++;
	}
	node* last_l1 = temp;	
	temp->next = l1;
	
	node *mov1=l2, *mov2=l2;
	
	while(len)
	{
		mov2=mov2->next; 
		len--;
	}
	
	do{
		mov1 = mov1->next;
		mov2 = mov2->next;
	}
	while(mov1!=mov2);
	
	last_l1->next = NULL;
	return mov1->val;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	node* l1= new node(3), *l2 = new node(99);
	node* temp1 = l1, *temp2 = l2;
	temp1->next = new node(7);
	temp2->next = new node(1);
	temp1 = temp1->next; temp2 = temp2->next;
	temp1->next = temp2->next = new node(8);
	temp1 = temp1->next; temp2 = temp2->next;
	temp1->next = temp2->next = new node(10);
	
	cout<<findNode(l1,l2)<<"\n";
}


