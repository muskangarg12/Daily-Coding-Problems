/*
Problem 32
Suppose you are given a table of currency exchange rates, represented as a 2D array. Determine whether there is a possible arbitrage: that is, whether there is some sequence of trades you can make, starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.
There are no transaction costs and you can trade fractional quantities.
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

bool negcycle(int cur[][1004], int n)
{
	int mindist[n];
	memset(mindist,Max,sizeof(mindist));
	
	int source=0;
	mindist[source]=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(mindist[k]>mindist[j]+cur[j][k])
					mindist[k]=mindist[j]+cur[j][k];
					
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			if(mindist[k]>mindist[j]+cur[j][k])
			{
				mindist[k]=mindist[j]+cur[j][k];
				return 1;
			}
			
	return 0;		
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	int cur[n][1004];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>cur[i][j];
			
	cout<<negcycle(cur,n)<<"\n";		
}

