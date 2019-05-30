/*
Problem 37
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
You may also use a list or array to represent a set.
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

vector< vector<int>> powerset(int a[], int n)
{
	vector< vector<int> > ps;
	int tot = 1<<n;
	for(int i=0;i<tot;i++)
	{
		int x=i, idx=0;
		vector< int > temp;
		while(x)
		{
			if(x&1)
				temp.pb(a[idx]);
			x>>=1;
			idx++;	
		}
		ps.pb(temp);
	}
	return ps;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector< vector<int> >  ps = powerset(a,n);	
	for(auto x : ps)
	{
		cout<<"{ ";
		for(auto y: x)
			cout<<y<<", ";
		cout<<"},\n";
	}
}

