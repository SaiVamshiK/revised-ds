/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/

#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *child[26];
    bool isEnd;
    Node()
    {
        memset(child,0,sizeof(child));
        isEnd=false;
    }
};
void insert(Node *root,string str)
{
    Node *cur=root;
    for(int i=0;i<(str.size());i++)
    {
        int idx=str[i]-'a';
        if(!cur->child[idx])
        {
            cur->child[idx]=new Node();
        }
        cur=cur->child[idx];
    }
    cur->isEnd=true;
}
bool search(string str,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(str.size());i++)
    {
        int idx=str[i]-'a';
        if(!cur->child[idx])
        {
            return false;
        }
        cur=cur->child[idx];
    }
    return cur->isEnd;
}
bool solve(string str,Node *root)
{
    if(search(str,root)) return true;
    int n=str.size();
    for(int i=0;i<(n-1);i++)
    {
        string left=str.substr(0,i+1);
        string right=str.substr(i+1,n-i-1);
        if(search(left,root)&&solve(right,root))
        {
            return true;
        }
    }
    return false;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string str;
	    Node *root=new Node();
	    for(int i=0;i<n;i++)
	    {
	        cin>>str;
	        insert(root,str);
	    }
	    cin>>str;
	    if(solve(str,root))
	    {
	        cout<<"1"<<endl;
	    }else{
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
