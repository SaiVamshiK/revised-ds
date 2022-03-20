#include<bits/stdc++.h>
using namespace std;
char find(char ch)
{
	if((ch>='a')&&(ch<='z'))
	{
		return ch-32;
	}
	return ch+32;
}
void func(string inp,int i,int n,string op,vector<string> &ans)
{
	if(i==n)
	{
		ans.push_back(op);
		return ;
	}
	char cur_ch=inp[i];
	char comp=find(cur_ch);
	op.push_back(cur_ch);
	func(inp,i+1,n,op,ans);
	op.pop_back();
	op.push_back(comp);
	func(inp,i+1,n,op,ans);
}
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<string>	ans;
	string op="";
	func(s,0,n,op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		cout<<ans[i]<<' ';
	}
}










