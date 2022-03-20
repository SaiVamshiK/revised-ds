
Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

Input Format
The first and only line of the test case contains the input string.

Constraints
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

Sample Input
ABA
Sample Output
AAB
ABA
BAA


#include<bits/stdc++.h>
using namespace std;
void func(string &inp,bool *visited,int n,string &op,vector<string> &ans)
{
	if(op.size()==n)
	{
		ans.push_back(op);
		return ;
	}
	char prev;
	bool done=false;
	for(int i=0;i<n;i++)
	{
		char cur=inp[i];
		if(!visited[i]&&((done==false)||(prev!=cur)))
		{
            done=true;
			visited[i]=true;
			op.push_back(cur);
			func(inp,visited,n,op,ans);
			visited[i]=false;
            op.pop_back();
			prev=cur;
		}
	}
}
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	int n=s.size();
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	vector<string> ans;
	string op="";
	func(s,visited,n,op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		cout<<ans[i]<<endl;
	}
}
















