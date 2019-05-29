/*
Problem 29
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
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

string decode(string s)
{
	string ans="";
	int count=1;
	char val=s[0];
	for(int i=1;i<s.length();i++)
	{
		if(s[i]==val)
		{
			count++;
		}
		else
		{
			ans+=(count+48);
			ans+=val;
			val=s[i];
			count=1;
		}
	}
	ans+=(count+48);
	ans+=val;
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin>>s;
	cout<<decode(s)<<"\n";
}

