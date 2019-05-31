/*
Problem 34
Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the first one alphabetically).
For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.
As another example, given the string "google", you should return "elgoogle".
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

string solve( string s )
{
	int n = s.length();
	int dp[n][n]={0};
	string ret[n][n];
	for(int i=0;i<n;i++)
		ret[i][i]=s[i];
	for(int gap=1;gap<n;gap++)
	{
		for(int st=0,end=gap;end<n;st++,end++)
		{
			if(s[st]==s[end])
			{
				dp[st][end]=dp[st+1][end-1];
				ret[st][end]=s[st]+ret[st+1][end-1]+s[end];
			}
			else
			{
				dp[st][end]=min(dp[st+1][end], dp[st][end-1])+1;
				if(dp[st+1][end]<dp[st][end-1])
					ret[st][end]=s[st]+ret[st+1][end]+s[st];
				else
				if(dp[st+1][end]>dp[st][end-1])
					ret[st][end]=s[end]+ret[st][end-1]+s[end];
				else
				{
					if(s[end]<s[st])
						ret[st][end]=s[end]+ret[st][end-1]+s[end];
					else
						ret[st][end]=s[st]+ret[st+1][end]+s[st];
				}
			}
		}
	}
	return ret[0][n-1];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin>>s;
	cout<<solve(s)<<"\n";
}

