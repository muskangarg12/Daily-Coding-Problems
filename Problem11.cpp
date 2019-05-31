/*
Problem 11
Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.
For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
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

struct trienode{
	trienode* alph[26];
	int endofword;
	
	trienode(){
		for(int i=0;i<26;i++)
			alph[i]=NULL;
		endofword=-1;	
	}
};

string dict[100008];

void insert(trienode* root, int idx)
{
	string s = dict[idx];
	trienode* temp=root;
	
	for(int i=0;i<s.length();i++)
	{
		if(!temp->alph[s[i]-'a'])
			temp->alph[s[i]-'a']=new trienode();
		temp = temp->alph[s[i]-'a'];	
	}	
	
	temp->endofword=idx;
}

trienode* search(trienode* root, string s)
{
	trienode* temp=root;
	
	for(int i=0;i<s.length();i++)
	{
		if(!temp->alph[s[i]-'a'])
			return NULL;
		temp = temp->alph[s[i]-'a'];	
	}	
	
	return temp;
}

void display(trienode* root)
{
	trienode* temp=root;
	
	if(temp->endofword!=-1)
		cout<<dict[temp->endofword]<<"\n";
	
	for(int i=0;i<26;i++)
		if(temp->alph[i])
			display(temp->alph[i]);	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	trienode* root= new trienode();
	
	string s; cin>>s;
	
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>dict[i];
		insert(root,i);
	}
	
	root = search(root,s);
	if(root)
		display(root);
	else
		cout<<"No string exist\n";	
}

