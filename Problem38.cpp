/*
Problem 38
You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.
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

int ans;

bool check(int done[], int row, int col, int n)
{
	for(int i=0;i<n;i++)
		if(done[i]!=-1)
			if(abs(done[i]-row)==abs(i-col))
				return 0;
	return 1;			
}

bool begin(int row,int n,int done[])
{
	if(row==n)	
	{
		ans++;
		return 1;
	}
	bool ret=0;
	for(int i=0;i<n;i++)
	{
		if(done[i]==-1)
		{
			if(check(done,row,i,n))
			{
				done[i]=row;
				if(begin(row+1,n,done))
					ret = 1;
				done[i]=-1;	
			}
		}
	}
	return ret;
}

void NQueen(int n)
{
	ans=0;
	int done[n];
	memset(done,-1,sizeof(done));
	if(begin(0,n,done))
		cout<<ans<<"\n";
	else
		cout<<"No Solution\n";	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	NQueen(n);
}

