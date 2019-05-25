/*
Problem 4
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
You can modify the input array in-place.
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
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int j=0;	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=0) 
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; 
			j++;
		} 
	}	
	
	int i;
	for(i=0; j<n ;i++, j++)
		arr[i]=arr[j];
		
	for(i=0;i<n;i++)
	{
		if(arr[abs(arr[i])-1]>0)
			arr[abs(arr[i])-1] *= (-1);
	}
		
	for(i=0;i<n;i++)
		if(arr[i]>0)
		{
			cout<<i+1<<"\n";
			break;
		}
}

