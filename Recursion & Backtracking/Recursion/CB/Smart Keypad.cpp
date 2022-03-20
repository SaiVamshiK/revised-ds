
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c

#include<bits/stdc++.h>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void func(string &inp,int idx,int n,string &op,vector<string> &ans)
{
	if(idx==n)
	{
		ans.push_back(op);
		return ;
	}
	string cur=table[inp[idx]-'0'];
	for(int i=0;i<(cur.size());i++)
	{
		op.push_back(cur[i]);
		func(inp,idx+1,n,op,ans);
		op.pop_back();
	}
}
int main()
{
	string s;
	cin>>s;
	vector<string > ans;
	string op="";
	func(s,0,s.size(),op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		cout<<(ans[i])<<endl;
	}
}






