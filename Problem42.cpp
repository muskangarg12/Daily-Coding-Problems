/*
Problem 42
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.
Integers can appear more than once in the list. You may assume all numbers in the list are positive.
For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
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

vector< int > solve(int arr[], int n, int sum)
{
	bool dp[n+1][sum+1];
	vector< int > set[n+1][sum+1];
		
	for(int i=0;i<=sum;i++)
		dp[0][i]=0;	
		
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=1;
		if(i>0)
		{
			dp[i][arr[i]]=1;
			set[i][arr[i]].pb(arr[i]);
		}
	}
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i]>j)
			{
				dp[i][j]=dp[i-1][j];
				set[i][j]=set[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];	
				if(dp[i-1][j])
					set[i][j]=set[i-1][j];
				else
				if(dp[i-1][j-arr[i]])
				{
					set[i][j]=set[i-1][j-arr[i]];
					set[i][j].pb(arr[i]);
				}	
			}
			/*cout<<i<<" ** "<<j<<" && ";
			for(auto x: set[i][j])
				cout<<x<<" ";
			cout<<"\n";	*/
		}
	}
	
	return set[n][sum];		
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,sum; cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cin>>sum;	
	vector< int > ans = solve(arr,n,sum);
	
	if(ans.empty())
		cout<<"Not Possible\n";
	else	
		for(auto x : ans)
			cout<<x<<" ";	
}

