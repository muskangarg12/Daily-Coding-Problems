/*
Problem 23
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.
For example, given the following board:
[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
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

int dp[1008][1008],n,m,endr,endc;
bool a[1008][1008], vis[1008][1008];

int minSteps(int r, int c)
{
	if(r==endr && c==endc)	return 0;
	vis[r][c] = 1;
	
	int ans = Max;
	if(r+1<m && !a[r+1][c])
	{
		if(!vis[r+1][c])
		{
			int x = minSteps(r+1,c);
			if(x!=-1)
				ans = min(ans, 1+x);
		}
		else
		{
			if(dp[r+1][c]!=-1)
				ans = min(ans, 1+dp[r+1][c]);
		}
	}
	if(r-1>=0 && !a[r-1][c])
	{
		if(!vis[r-1][c])
		{
			int x = minSteps(r-1,c);
			if(x!=-1)
				ans = min(ans, 1+x);
		}
		else
		{
			if(dp[r-1][c]!=-1)
				ans = min(ans, 1+dp[r-1][c]);
		}
	}
	if(c+1<n && !a[r][c+1])
	{
		if(!vis[r][c+1])
		{
			int x = minSteps(r,c+1);
			if(x!=-1)
				ans = min(ans, 1+x);
		}
		else
		{
			if(dp[r][c+1]!=-1)
				ans = min(ans, 1+dp[r][c+1]);
		}
	}
	if(c-1>=0 && !a[r][c-1])
	{
		if(!vis[r][c-1])
		{
			int x = minSteps(r,c-1);
			if(x!=-1)
				ans = min(ans, 1+x);
		}
		else
		{
			if(dp[r][c-1]!=-1)
				ans = min(ans, 1+dp[r][c-1]);
		}
	}
	
	if(ans==Max)
		return -1;
	else
	{
		dp[r][c]=ans;
		return ans;	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	
	int str,stc;
	cin>>str>>stc>>endr>>endc;
	
	memset(dp,-1,sizeof(dp));
	
	if(str==endr && stc==endc)
	{
		cout<<"0\n";
		return 0;
	}
	
	int ans=minSteps(str,stc);
	if(ans==-1)
		cout<<"NULL\n";
	else
		cout<<ans<<"\n";			
}

