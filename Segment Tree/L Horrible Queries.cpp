
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(ll *tree,ll *lazy,ll s,ll e,ll i,ll l,ll r,ll val)
{
    if(lazy[i]!=0)
    {
        tree[i]+=((e-s+1)*(lazy[i]));
        if(s!=e)
        {
            lazy[(2*i)]+=lazy[i];
            lazy[(2*i)+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>e||(r<s))
    {
        return ;
    }
    if((l<=s)&&(r>=e))
    {
        tree[i]+=((e-s+1)*(val));
        if(s!=e)
        {
            lazy[(2*i)]+=val;
            lazy[(2*i)+1]+=val;
        }
        return ;
    }
    ll mid=s+((e-s)/2);
    update(tree,lazy,s,mid,(2*i),l,r,val);
    update(tree,lazy,mid+1,e,(2*i)+1,l,r,val);
    tree[i]=(tree[(2*i)]+tree[(2*i)+1]);
    return ;
}
ll query(ll *tree,ll *lazy,ll s,ll e,ll i,ll l,ll r)
{
    if(lazy[i]!=0)
    {
        tree[i]+=((e-s+1)*(lazy[i]));
        if(s!=e)
        {
            lazy[(2*i)]+=lazy[i];
            lazy[(2*i)+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    if((l>e)||(r<s))
    {
        return 0;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    ll mid=s+((e-s)/2);
    ll ans1=query(tree,lazy,s,mid,(2*i),l,r);
    ll ans2=query(tree,lazy,mid+1,e,(2*i)+1,l,r);
    return ans1+ans2;
}
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll *tree=new ll[(4*n)];
        ll *lazy=new ll[(4*n)];
        for(ll i=0;i<(4*n);i++)
        {
            tree[i]=0;
            lazy[i]=0;
        }
        while(q--)
        {
            ll ch;
            cin>>ch;
            if(ch==0)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                l--;r--;
                update(tree,lazy,0,n-1,1,l,r,val);
            }else{
                ll l,r;
                cin>>l>>r;
                l--;r--;
				ll ans=query(tree,lazy,0,n-1,1,l,r);
                cout<<ans<<endl;
            }
        }
    }
}




















