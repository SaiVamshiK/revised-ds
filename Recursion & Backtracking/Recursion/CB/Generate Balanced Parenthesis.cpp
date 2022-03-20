#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
**************************************************
For sorting interchange the if loops
**************************************************
void func(int op,int cl,string &ot,vector<string> &ans,int n)
{
	if(op==cl&&(op==n))
	{
		ans.push_back(ot);
		return ;
	}
	if(op==cl)
	{
		ot.push_back('(');
		func(op+1,cl,ot,ans,n);
		ot.pop_back();
	}
	if(op>cl)
	{
        ot.push_back(')');
		func(op,cl+1,ot,ans,n);
		ot.pop_back();
		if(op!=n)
		{
			ot.push_back('(');
			func(op+1,cl,ot,ans,n);
			ot.pop_back();
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	string ot="";
	vector<string> ans;
	func(0,0,ot,ans,n);
	for(int i=0;i<(ans.size());i++)
	{
		cout<<ans[i]<<endl;
	}
}
