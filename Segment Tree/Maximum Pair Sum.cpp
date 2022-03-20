
You are given a sequence A[1], A[2], ..., A[N], ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 = i = N, and x, 0 = x = 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 = x < y = N.
You must find i and j such that x = i, j = y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

#include<bits/stdc++.h>
using namespace std;
struct node{
  	int fmaxi,smaxi;  
};
void bt(int *a,node *tree,int s,int e,int i)
{
    if(s==e)
    {
        tree[i].fmaxi=a[s];
        tree[i].smaxi=INT_MIN;
        return ;
    }
    int mid=(s)+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,1+(2*i));
    node x=tree[(2*i)],y=tree[(2*i)+1];
    tree[i].fmaxi=max(x.fmaxi,y.fmaxi);
    tree[i].smaxi=max(min(x.fmaxi,y.fmaxi),max(x.smaxi,y.smaxi));
}
node query(node *tree,int s,int e,int l,int r,int i)
{
    if(l>e||(r<s))
    {
        node ret;
        ret.fmaxi=0;
        ret.smaxi=0;
        return ret;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    int mid=s+((e-s)/2);
    node ans1=query(tree,s,mid,l,r,(2*i));
    node ans2=query(tree,mid+1,e,l,r,(2*i)+1);
    node ret;
    ret.fmaxi=max(ans1.fmaxi,ans2.fmaxi);
    ret.smaxi=max(min(ans1.fmaxi,ans2.fmaxi),max(ans1.smaxi,ans2.smaxi));
    return ret;
}
void update(node *tree,int s,int e,int idx,int val,int i)
{
    if(s==e&&(s==idx))
    {
        tree[i].fmaxi=val;
        tree[i].smaxi=INT_MIN;
        return ;
    }
    int mid=s+((e-s)/2);
    if(idx<=mid)
    {
        update(tree,s,mid,idx,val,(2*i));
    }else{
        update(tree,mid+1,e,idx,val,(2*i)+1);
    }
    node x=tree[(2*i)],y=tree[(2*i)+1];
    tree[i].fmaxi=max(x.fmaxi,y.fmaxi);
    tree[i].smaxi=max(min(x.fmaxi,y.fmaxi),max(x.smaxi,y.smaxi));
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    node *tree=new node[(4*n)];
    bt(a,tree,0,n-1,1);
    int q;
    cin>>q;
    char ch;
    while(q--)
    {
        cin>>ch;
        if(ch=='Q')
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            node ans=query(tree,0,n-1,l,r,1);
            cout<<(ans.fmaxi+ans.smaxi)<<endl;
        }else{
            int idx,val;
            cin>>idx>>val;
            idx--;
            update(tree,0,n-1,idx,val,1);
        }
    }
}


