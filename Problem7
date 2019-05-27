/*
Problem 7
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
You can assume that the messages are decodable. For example, '001' is not allowed.
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

int dp[100009];

int decodeCount(string s, int idx)
{
	if(idx >= s.length())
		return 1;
		
	if(idx == s.length()-1)
	{
		if(s[idx]=='0')	
			return 0;
		else	
			return 1;
	}
	
	if(dp[idx]!=-1)	return dp[idx];
	
	dp[idx] = 0;
	if(s[idx]=='0')	
		return dp[idx] = decodeCount(s,idx+1);
	if((s[idx]<='1') || (s[idx]=='2' && s[idx+1]<='6'))
		dp[idx]+=decodeCount(s,idx+2);
	if(s[idx+1]!='0')
		dp[idx]+=decodeCount(s,idx+1);
	
	return dp[idx];				
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string msg;cin>>msg;
	
	memset(dp,-1,sizeof(dp));
	
	cout<<decodeCount(msg, 0)<<"\n";
}

