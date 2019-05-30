/*
Problem 33
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.
Recall that the median of an even-numbered list is the average of the two middle numbers.
For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
2
1.5
2
3.5
2
2
2
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

void contMedian(int n)
{
	priority_queue< int > left;
	priority_queue< int,vector<int>, greater<int> > right;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(left.size()!=right.size())
		{
			if(left.size()<right.size())
			{
				if(x<=right.top())
				{
					left.push(x);
				}
				else
				{
					left.push(right.top());
					right.pop();
					right.push(x);
				}
			}
			else
			{
				if(x>=left.top())
				{
					right.push(x);
				}
				else
				{
					right.push(left.top());
					left.pop();
					left.push(x);
				}
			}
			cout<<(left.top()+right.top())/2.0<<"\n";
		}
		else
		{
			if(left.empty() && right.empty())
			{
				left.push(x);
				cout<<left.top()<<"\n";
			}
			else
			{
				if(x<=right.top())
				{
					left.push(x);
					cout<<left.top()<<"\n";
				}
				else	
				{
					right.push(x);
					cout<<right.top()<<"\n";
				}
			}	
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	contMedian(n);
}

