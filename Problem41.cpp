/*
Problem 41
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.
For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.
Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
*/
#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
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

int n;
map< string, set< string > > adj;
vector< string > ans;

bool solve(string s)
{
	if(ans.size()==n+1)
		return 1;
	if(!adj.count(s))
		return 0;	
	for(auto x : adj[s])
	{
		ans.pb(x);
		adj[s].erase(x);
		if(!solve(x))
			return 0;
		else
			break;	
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	
	string s1, s2, start;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2;
		adj[s1].insert(s2);
	} 
	cin>>start;
	
	ans.clear();
	ans.pb(start);
	if(solve(start))
		for(auto x : ans)
			cout<<x<<" -> ";
	else
		cout<<"NULL\n";		
}

