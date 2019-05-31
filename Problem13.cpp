/*
Problem 13
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

//reference : http://anothercasualcoder.blogspot.com/2018/09/two-pointers-for-linear-solution.html
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
	string s;
	cin>>s;
	int k; cin>>k;
	
	int n= s.length();
	int front=0, back=0, ansbeg=0, ansend=0;
	int pres[100]={0}, count=0;
	
	while(front<n)
	{
		if((count<k && pres[s[front]]==0) || (count<=k && pres[s[front]]>0))
		{
			if((front-back)>(ansend-ansbeg))
				ansend=front, ansbeg=back;
			if(pres[s[front]]==0)
				count++;
			pres[s[front]]++;	
			front++;	
		}
		else
		{
			if(pres[s[back]]==1)
				count--;
			pres[s[back]]--;
			back++;	
		}
	}
	
	for(int i=ansbeg;i<=ansend;i++)
		cout<<s[i];
}

