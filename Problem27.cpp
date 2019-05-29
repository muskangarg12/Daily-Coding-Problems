/*
Problem 27
Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
For example, given the string "([])[]({})", you should return true.
Given the string "([)]" or "((()", you should return false.
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

bool balanced(string s)
{
	stack< char > acc;
	for(auto x: s)
	{
		if(x=='(' || x=='[' || x=='{')
			acc.push(x);
		else
		{
			if(!acc.empty())
			{
				char y = acc.top();
				if((y=='(' && (x=='}' || x==']')) || (y=='[' && (x=='}' || x==')')) || (y=='{' && (x==')' || x==']')))
					return false;
				acc.pop();	
			}
			else
				return false;
		}	
	}
	if(!acc.empty())
		return false;
	return true;	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin>>s;
	cout<<balanced(s)<<"\n";
}

