#include<bits/stdc++.h>
using namespace std;
void func(int *a,int idx,int n,vector<int> &op,int sum,vector<vector<int>> &ans)
{
	if(sum==0)
	{
		ans.push_back(op);
		return ;
	}
    if(idx==n)
    {
        return;
    }
	int prev=-1;
	for(int i=idx;i<n;i++)
	{
		int cur=a[i];
		if(cur<=sum&&(cur!=prev))
		{
			op.push_back(cur);
			func(a,i+1,n,op,sum-cur,ans);
			op.pop_back();
			prev=cur;
		}
	}
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
	sort(a,a+n);
	int sum;
	cin>>sum;
	vector<int> op;
	vector<vector<int>> ans;
	func(a,0,n,op,sum,ans);
	for(int i=0;i<(ans.size());i++)
	{
		for(int j=0;j<(ans[i].size());j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
}
