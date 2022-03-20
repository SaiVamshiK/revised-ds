

Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

#include<bits/stdc++.h>
using namespace std;
void bt(int *a,int *tree,int s,int e,int i)
{
	if(s==e)
    {
        tree[i]=a[s];
        return ;
    }
    int mid=s+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,(2*i)+1);
    tree[i]=min(tree[(2*i)],tree[(2*i)+1]);
}
int query(int *tree,int s,int e,int l,int r,int i)
{
    if((l>e)||(r<s))
    {
        return INT_MAX;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    int mid=s+((e-s)/2);
    int ans1=query(tree,s,mid,l,r,(2*i));
    int ans2=query(tree,mid+1,e,l,r,(2*i)+1);
    return min(ans1,ans2);
}
void update(int *tree,int s,int e,int i,int idx,int val)
{
    if(s==e&&(s==idx))
    {
        tree[i]=val;
        return ;
    }
    int mid=s+((e-s)/2);
    if(idx<=mid)
    {
        update(tree,s,mid,(2*i),idx,val);
    }else{
        update(tree,mid+1,e,(2*i)+1,idx,val);
    }
    tree[i]=min(tree[2*i],tree[(2*i)+1]);
}
int main() {
 	int n,q;
    cin>>n>>q;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int *tree=new int[(2*n)];
    bt(a,tree,0,n-1,1);
    char ch;
    while(q--)
    {
        cin>>ch;
        if(ch=='q')
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            int ans=query(tree,0,n-1,l,r,1);
            cout<<ans<<endl;
        }else{
            int idx,val;
            cin>>idx>>val;
            idx--;
            update(tree,0,n-1,1,idx,val);
        }
    }
}




