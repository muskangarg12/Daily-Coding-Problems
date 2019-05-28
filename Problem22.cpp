/*
Problem 22
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].
Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
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

vector< string > dict[26], ans;
string s;

bool retList(int idx)
{
	if(idx==s.length())	return 1;
	
	for(auto x: dict[s[idx]-'a'])
	{
		bool flag=1;
		for(int i=0;i<x.length();i++)
		{
			if((idx+i)==s.length())
				return 0;
			if(s[idx+i]!=x[i])	
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(retList(idx+x.length()))
			{
				ans.pb(x);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		dict[s[0]-'a'].pb(s);
	} 
	
	cin>>s;
	
	if(retList(0))
	{
		for(int i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<"\n";
	}
	else
		cout<<"NULL\n";
}

