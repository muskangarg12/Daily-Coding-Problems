/*
Problem 19
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
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
	int n,k; cin>>n>>k;
	int c[n][k];
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
			cin>>c[i][j];
	
	int dp[n][k];
	for(int i=0;i<k;i++)
		dp[0][i] = c[0][i];
		
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			dp[i][j] = c[i][j];
			int x=Max;
			for(int l=0;l<k;l++)
				if(l!=j)
					x = min(x,dp[i-1][l]);
			dp[i][j] += x;		
		}
	}			
	
	int ans = dp[n-1][0]; 
	for(int i=1;i<k;i++)
		ans = min(ans,dp[n-1][i]);
		
	cout<<ans<<"\n";	
}

