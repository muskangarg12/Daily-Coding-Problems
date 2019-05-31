/*
Problem 44
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.
Given an array, count the number of inversions it has. Do this faster than O(N^2) time.
You may assume each element in the array is distinct.
For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/
#include<bits/stdc++.h>
using namespace std;

long long merge(long long a[], long long l, long long mid, long long r)
{
    long long i=l,j=mid+1,idx=l,ans=0;
    long long temp[r+1];
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[idx]=a[i], i++;
        }
        else
        {
            temp[idx]=a[j], j++;
            ans+=(mid-i+1);
        }
        idx++;
    }
    while(i<=mid)
        temp[idx++]=a[i++];
    while(j<=r)
        temp[idx++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=temp[i];
    return ans;    
}

long long mergesort(long long a[], long long l, long long r)
{
    long long ans=0;
    if(l<r)
    {
        long long mid=(l+r)/2;
        
        ans+=mergesort(a,l,mid);
        ans+=mergesort(a,mid+1,r);
        
        ans+=merge(a,l,mid,r);
    }
    return ans;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<mergesort(a,0,n-1)<<"\n";    
    }
	return 0;
}
