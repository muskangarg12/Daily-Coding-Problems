/*
Problem 1.
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
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
      int n, k;
      cin>>n>>k;

      int arr[n];
      for(int i=0;i<n;i++)
        cin>>arr[i];

      set< int > exist;
      for(int i=0;i<n;i++)
      {
            if(exist.find(k-arr[i]) != exist.end())
            {
                cout<<"YES\n";
                return 0;
            }
            exist.insert(arr[i]);
      }	
      cout<<"NO\n";
      return 0;
}

