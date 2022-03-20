#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct tree_node{
  	ll sum,sq_sum;  
};
struct lazy_node{
  	ll type;
    ll val;
};
void bt(ll *a,tree_node *tree,ll s,ll e,ll i)
{
    if(s==e)
    {
        tree[i].sum=a[s];
        tree[i].sq_sum=(a[s]*a[s]);
        return ;
    }
    ll mid=s+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,(2*i)+1);
    tree[i].sum=tree[(2*i)].sum+tree[(2*i)+1].sum;
    tree[i].sq_sum=tree[(2*i)].sq_sum+tree[(2*i)+1].sq_sum;
}
ll query(tree_node *tree,lazy_node *lazy,ll s,ll e,ll i,ll l,ll r)
{
    if(lazy[i].type!=-1)
    {
        if(lazy[i].type==0)
        {
            ll inc=lazy[i].val;
            ll len=e-s+1;
            ll prev_sum=tree[i].sum;
            tree[i].sum+=(len*(inc));
            tree[i].sq_sum+=((len*inc*inc)+(2*inc*prev_sum));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }else{
            ll set=lazy[i].val;
            ll len=e-s+1;
            tree[i].sum=((len)*(set));
            tree[i].sq_sum=((len)*(set*set));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }
    }
    if((l>e)||(r<s))
    {
        return 0;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i].sq_sum;
    }
    ll mid=((s)+((e-s)/2));
    ll ans1=query(tree,lazy,s,mid,(2*i),l,r);
    ll ans2=query(tree,lazy,mid+1,e,(2*i)+1,l,r);
    return ans1+ans2;
}

void update_set(tree_node *tree,lazy_node *lazy,ll s,ll e,ll i,ll l,ll r,ll x)
{
    if(lazy[i].type!=-1)
    {
        if(lazy[i].type==0)
        {
            ll inc=lazy[i].val;
            ll len=e-s+1;
            ll prev_sum=tree[i].sum;
            tree[i].sum+=(len*(inc));
            tree[i].sq_sum+=((len*inc*inc)+(2*inc*prev_sum));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }else{
            ll set=lazy[i].val;
            ll len=e-s+1;
            tree[i].sum=((len)*(set));
            tree[i].sq_sum=((len)*(set*set));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }
    }
    if((l>e)||(r<s))
    {
        return ;
    }
    if((l<=s)&&(r>=e))
    {
     	ll set=x;
        ll len=e-s+1;
        tree[i].sum=((len)*(set));
        tree[i].sq_sum=((len)*(set*set));
        if(s!=e)
        {
            lazy[(2*i)].type=1;
            lazy[(2*i)].val=x;
            lazy[(2*i)+1].type=1;
            lazy[(2*i)+1].val=x;
        }
        return ;
    }
    ll mid=s+((e-s)/2);
    update_set(tree,lazy,s,mid,(2*i),l,r,x);
    update_set(tree,lazy,mid+1,e,(2*i)+1,l,r,x);
    tree[i].sum=tree[(2*i)].sum+tree[(2*i)+1].sum;
    tree[i].sq_sum=tree[(2*i)].sq_sum+tree[(2*i)+1].sq_sum;
}
void update_add(tree_node *tree,lazy_node *lazy,ll s,ll e,ll i,ll l,ll r,ll x)
{
    if(lazy[i].type!=-1)
    {
        if(lazy[i].type==0)
        {
            ll inc=lazy[i].val;
            ll len=e-s+1;
            ll prev_sum=tree[i].sum;
            tree[i].sum+=(len*(inc));
            tree[i].sq_sum+=((len*inc*inc)+(2*inc*prev_sum));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }else{
            ll set=lazy[i].val;
            ll len=e-s+1;
            tree[i].sum=((len)*(set));
            tree[i].sq_sum=((len)*(set*set));
            if(s!=e)
            {
            	lazy[(2*i)].type=lazy[i].type;
                lazy[(2*i)].val=lazy[i].val;
                lazy[(2*i)+1].type=lazy[i].type;
                lazy[(2*i)+1].val=lazy[i].val;
            }
            lazy[i].type=-1;
            lazy[i].val=0;
        }
    }
    if((l>e)||(r<s))
    {
        return ;
    }
    if((l<=s)&&(r>=e))
    {
     	ll inc=x;
        ll len=r-l+1;
        ll prev_sum=tree[i].sum;
        tree[i].sum+=(len*(inc));
        tree[i].sq_sum+=((len*inc*inc)+(2*inc*prev_sum));  
        if(s!=e)
        {
         	lazy[(2*i)].type=0;
            lazy[(2*i)].val=inc;
            lazy[(2*i)+1].type=0;
            lazy[(2*i)+1].val=inc;   
        }
        return ;
    }
    ll mid=s+((e-s)/2);
    update_add(tree,lazy,s,mid,(2*i),l,r,x);
    update_add(tree,lazy,mid+1,e,(2*i)+1,l,r,x);
    tree[i].sum=tree[(2*i)].sum+tree[(2*i)+1].sum;
    tree[i].sq_sum=tree[(2*i)].sq_sum+tree[(2*i)+1].sq_sum;
}
int main() {
    ll t;
    cin>>t;
    ll idx=1;
    while(t--)
    {
        cout<<"Case "<<idx<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        ll *a=new ll[n];
  		for(ll i=0;i<n;i++)      
        {
            cin>>a[i];
        }
        tree_node *tree=new tree_node[(4*n)+1];
        bt(a,tree,0,n-1,1);
        lazy_node *lazy=new lazy_node[(4*n)+1];
        for(ll i=0;i<=(4*n);i++)
        {
            lazy[i].type=-1;
            lazy[i].val=0;
        }
        while(q--)
        {
            ll ch;
            cin>>ch;
            if(ch==2)
            {
                ll l,r;
                cin>>l>>r;
                l--;r--;
                ll ans=query(tree,lazy,0,n-1,1,l,r);
                cout<<ans<<endl;
            }else if(ch==1){
                // add 
                ll l,r,x;
                cin>>l>>r>>x;
                l--;r--;
                update_add(tree,lazy,0,n-1,1,l,r,x);
            }else{
                // set
                ll l,r,x;
                cin>>l>>r>>x;
                l--;r--;
                update_set(tree,lazy,0,n-1,1,l,r,x);
            }
        }
        idx++;
    }
}













