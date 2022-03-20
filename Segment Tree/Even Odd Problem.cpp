Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

#include<bits/stdc++.h>
using namespace std;
struct node{
  	int even,odd;
};
void bt(int *a,node *tree,int s,int e,int i)
{
    if(s==e)
    {
        if(a[s]%2==0)
        {
            tree[i].even=1;
            tree[i].odd=0;
        }else{
            tree[i].odd=1;
            tree[i].even=0;
        }
        return ;
    }
    int mid=s+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,1+(2*i));
    tree[i].odd=tree[(2*i)].odd+tree[(2*i)+1].odd;
    tree[i].even=tree[(2*i)].even+tree[(2*i)+1].even;
}
void update(node *tree,int s,int e,int i,int idx,int val)
{
    if(s==e&&(idx==s))
    {
        if(val%2==0)
        {
            tree[i].odd=0;
            tree[i].even=1;
        }else{
            tree[i].odd=1;
            tree[i].even=0;
        }
        return ;
    }
	int mid=s+((e-s)/2);
    if(idx<=mid)
    {
        update(tree,s,mid,(2*i),idx,val);
    }else{
        update(tree,mid+1,e,(2*i)+1,idx,val);
    }
	tree[i].odd=tree[(2*i)].odd+tree[(2*i)+1].odd;
    tree[i].even=tree[(2*i)].even+tree[(2*i)+1].even;
}
node query(node *tree,int s,int e,int i,int l,int r)
{
	if(l>e||(r<s))
    {
        node ret;
        ret.odd=0;
        ret.even=0;
        return ret;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    int mid=s+((e-s)/2);
    node left=query(tree,s,mid,2*i,l,r);
    node right=query(tree,mid+1,e,1+(2*i),l,r);
    node ret;
    ret.odd=left.odd+right.odd;
    ret.even=left.even+right.even;
    return ret;
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
    int ch;
    while(q--)
    {
        cin>>ch;
        if(ch==0)
        {
            int idx,val;
            cin>>idx>>val;
            idx--;
            update(tree,0,n-1,1,idx,val);
        }else 
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            node ans=query(tree,0,n-1,1,l,r);
            if(ch==1)
            {
                cout<<ans.even<<endl;
            }else{
                cout<<ans.odd<<endl;
            }
        }
    }
}
