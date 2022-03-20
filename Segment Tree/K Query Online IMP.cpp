#include<bits/stdc++.h>
using namespace std;
void bt(int *a,vector<int> *tree,int s,int e,int i)
{
	if(s==e)
	{
		tree[i].push_back(a[s]);
		return ;
	}
	int mid=s+((e-s)/2);
	bt(a,tree,s,mid,(2*i));
	bt(a,tree,mid+1,e,1+(2*i));
	int x=0,y=0;
	while((x<(tree[(2*i)].size()))&&(y<(tree[(2*i)+1].size())))
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
	while((x<(tree[(2*i)].size())))
	{
		tree[i].push_back(tree[(2*i)][x]);
		x++;
	}
	while((y<(tree[(2*i)+1].size())))
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
		int cnt=upper_bound(tree[i].begin(),tree[i].end(),k)-(tree[i].begin());
		return total-cnt;
	}
	int mid=s+((e-s)/2);
	int ans1=query(tree,s,mid,(2*i),l,r,k);
	int ans2=query(tree,mid+1,e,1+(2*i),l,r,k);
	return ans1+ans2;
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
	bt(a,tree,0,n-1,1);
	int q;
	cin>>q;
	int ans=0;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		l=l^ans;
		r=r^ans;
		k=k^ans;
		ans=query(tree,0,n-1,1,l-1,r-1,k);
		cout<<ans<<endl;
	}
}










