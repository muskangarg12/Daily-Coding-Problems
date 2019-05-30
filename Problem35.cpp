/*
Problem 35
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
Do this in linear time and in-place.
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
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

void solve(char a[], int n)
{
	int beg=0, end=n-1, cur=0; 
	while(beg<=end && cur<=end)
	{
		if(a[cur]=='R')
		{
			a[cur]=a[beg];
			a[beg]='R';
			beg++;
		}
		else
		if(a[cur]=='B')
		{
			while(end>=beg && a[end]=='B')
				end--;
			if(end>=0)
			{	
				a[cur]=a[end];
				a[end]='B';
				end--;
				if(a[cur]=='R')
				{
					a[cur]=a[beg];
					a[beg]='R';
					beg++;
				}
			}
		}
		cur++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	char a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	solve(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

