
Take as input str, a string. Write a recursive function which prints all the words possible by rearranging the characters of this string which are in dictionary order larger than the given string.
The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10

Output Format
Display all the words which are in dictionary order larger than the string entered in a new line each. The output strings must be sorted.

Sample Input
cab

Sample Output
cba
Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only one of them is lexicographically greater than "cab". We only print "cba".

#include<bits/stdc++.h>
using namespace std;
void func(string s,bool *visited,int n,string op,vector<string > &ans)
{
	if(op.size()==n)
	{
		ans.push_back(op);
		return ;
	}
	char prev;
	bool temp=false;
	for(int i=0;i<n;i++)
	{
		char cur=s[i];
		if(!visited[i]&&((temp==false)||(cur!=prev)))
		{
			visited[i]=true;
			op.push_back(cur);
			func(s,visited,n,op,ans);
			op.pop_back();
			visited[i]=false;
			prev=cur;
			temp=true;
		}
	}
}
int main()
{
	string str;
	cin>>str;
	string s=str;
	sort(s.begin(),s.end());
	int n=s.size();
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	string op="";
	vector<string > ans;
	func(s,visited,n,op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		if(ans[i]==str)
        {
            int cur=i+1;
            for(int j=cur;j<(ans.size());j++)
            {
                cout<<ans[j]<<endl;
            }
            break;
        }
	}
}
