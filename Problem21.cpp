/*
Problem 21
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
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

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	multiset< pair< int, int > > time;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		time.insert({x,y});
	}
	
	multiset< int > s;
	for(auto curr : time)
	{
		for(auto x: s)
			if(x<curr.f)
				s.erase(x);
		s.insert(curr.s);
	}
	cout<<s.size()<<"\n";
}

