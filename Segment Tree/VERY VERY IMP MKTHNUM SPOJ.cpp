
REFER GFG

#include<bits/stdc++.h>
using namespace std;
void bt(vector<int> *tree,int s,int e,int i,vector<pair<int,int>> &a)
{
	if(s==e)
	{
		tree[i].push_back(a[s].second);
		return ;
	}
	int mid=s+((e-s)/2);
	bt(tree,s,mid,(2*i),a);
	bt(tree,mid+1,e,(2*i)+1,a);
	int x=0,y=0;
	while((x<(tree[(2*i)].size()))&&(y<(tree[(2*i)+1].size())))
	{
		if((tree[(2*i)][x])<(tree[(2*i)+1][y]))
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
	while(y<tree[(2*i)+1].size())
	{
		tree[i].push_back(tree[(2*i)+1][y]);
		y++;
	}
}
int query(vector<int> *tree,int s,int e,int i,int l,int r,int k)
{
	if(s==e)
	{
		return tree[i][0];
	}
	int x=upper_bound(tree[(2*i)].begin(),tree[(2*i)].end(),r)-tree[(2*i)].begin();
	int y=lower_bound(tree[(2*i)].begin(),tree[(2*i)].end(),l)-tree[(2*i)].begin();
	int cnt=x-y;
	int mid=s+((e-s)/2);
	if(cnt>=k)
	{
		return query(tree,s,mid,(2*i),l,r,k);
	}else{
		return query(tree,mid+1,e,(2*i)+1,l,r,k-cnt);
	}
}
int main()
{
	int n,q;
	cin>>n>>q;
	int *a=new int[n];
	vector<pair<int,int>> vec;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vec.push_back({a[i],i});
	}
	sort(vec.begin(),vec.end());
	vector<int> *tree=new vector<int>[(4*n)+1];
	bt(tree,0,n-1,1,vec);
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		l--;r--;
		int idx=query(tree,0,n-1,1,l,r,k);
		cout<<a[idx]<<endl;
	}
}
