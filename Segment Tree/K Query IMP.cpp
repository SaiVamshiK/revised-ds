#include<bits/stdc++.h>
using namespace std;
void bt(vector<int> *tree,int *a,int s,int e,int i)
{
	if(s==e)
	{
		tree[i].push_back(a[s]);
		return ;
	}
	int mid=s+((e-s)/2);
	bt(tree,a,s,mid,(2*i));
	bt(tree,a,mid+1,e,(2*i)+1);
	int x=0,y=0;
	while(x<(tree[(2*i)].size())&&(y<(tree[(2*i)+1].size())))
	{
		if(tree[(2*i)][x]<(tree[(2*i)+1][y]))
		{
			tree[i].push_back(tree[(2*i)][x]);
			x++;
		}else{
			tree[i].push_back(tree[(2*i)+1][y]);
			y++;
		}
	}
	while(x<(tree[(2*i)].size()))
	{
		tree[i].push_back(tree[(2*i)][x]);
		x++;
	}
	while(y<(tree[(2*i)+1].size()))
	{
		tree[i].push_back(tree[(2*i)+1][y]);
		y++;
	}
}
int query(vector<int> *tree,int s,int e,int i,int l,int r,int k)
{
	if(l>e||(r<s))
	{
		return 0;
	}
	if((l<=s)&&(r>=e))
	{
		int total=(e-s+1);
		int cnt=upper_bound(tree[i].begin(),tree[i].end(),k)-tree[i].begin();
		return (total-cnt);
	}
	int mid=s+((e-s)/2);
	int a1=query(tree,s,mid,(2*i),l,r,k);
	int a2=query(tree,mid+1,e,(2*i)+1,l,r,k);
	return a1+a2;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> *tree=new vector<int>[(4*n)+1];
	bt(tree,a,0,n-1,1);
	int q;
	cin>>q;
	while(q--)
	{
		int i,j,k;
		cin>>i>>j>>k;
		i--;j--;
		int ans=query(tree,0,n-1,1,i,j,k);
		cout<<ans<<endl;
	}
}
