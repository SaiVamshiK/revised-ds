#include<bits/stdc++.h>
using namespace std;
void bt(int *tree,int *a,int s,int e,int i)
{
	if(s==e){
		tree[i]=a[s];
		return ;
	}
	int mid=s+((e-s)/2);
	bt(tree,a,s,mid,(2*i));
	bt(tree,a,mid+1,e,(2*i)+1);
	tree[i]=min(tree[(2*i)],tree[(2*i)+1]);
}
int query(int *tree,int s,int e,int i,int l,int r)
{
	if(l>e||(r<s))
	{
		return INT_MAX;
	}
	if((l<=s)&&(r>=e))
	{
		return tree[i];
	}
	int mid=s+((e-s)/2);
	int ans1=query(tree,s,mid,(2*i),l,r);
	int ans2=query(tree,mid+1,e,(2*i)+1,l,r);
	return min(ans1,ans2);
}
void update(int *tree,int s,int e,int i,int idx,int val)
{
	if(s==e&&(idx==s))
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
	tree[i]=min(tree[(2*i)],tree[(2*i)+1]);
}
int main()
{
	int n,q;
	cin>>n>>q;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int *tree=new int[(4*n)+1];
	bt(tree,a,0,n-1,1);
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			cout<<query(tree,0,n-1,1,l,r)<<endl;
		}else{
			int idx,val;
			cin>>idx>>val;
			idx--;
			update(tree,0,n-1,1,idx,val);
		}
	}
}
