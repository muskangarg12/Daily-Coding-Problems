/*
Problem 18
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:
10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
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
	int k,i; cin>>k;
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	deque< int > window;
	for(i=0;i<k;i++)
	{
		while(!window.empty() && a[i]>=a[window.back()])
			window.pop_back();
		window.push_back(i);	
	} 	
	
	cout<<a[window.front()]<<" ";
	for(;i<n;i++)
	{
		if(!window.empty() && window.front()<=(i-k))
			window.pop_front();
		while(!window.empty() && a[i]>=a[window.back()])
			window.pop_back();	
		window.push_back(i);		
		cout<<a[window.front()]<<" ";
	}
}

