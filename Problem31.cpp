/*
Problem 31
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.
Given two strings, compute the edit distance between them.
*/

//reference : https://lawrencewu.me/2015/02/15/levenshtein-distance.html 
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

int solve(string s1, string s2)
{
	int x=s1.length()+1, y=s2.length()+1;
	int edit[x][y];
	
	for(int i=0;i<y;i++)
		edit[0][i]=i;
		
	for(int i=0;i<x;i++)
		edit[i][0]=i;
		
	for(int i=1;i<x;i++)
		for(int j=1;j<y;j++)
			if(s1[i-1]==s2[j-1])
				edit[i][j]=edit[i-1][j-1];
			else
				edit[i][j]=min(edit[i-1][j-1], min(edit[i-1][j], edit[i][j-1]))+1;	 
		
	return edit[x-1][y-1];	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s1, s2; cin>>s1>>s2;
	cout<<solve(s1,s2)<<"\n";
}

