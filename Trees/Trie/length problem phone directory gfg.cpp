/*
Example:
Input:
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output:

geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explanation:

By running the query on contact list, we get, 
Suggestions based on "g" are: 
geeikistest geeksforgeeks geeksfortest 
Suggestions based on "ge" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "gee" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "geei" are:
geeikistest
No Results Found for "geeip", So print "0".
No Results Found for "geeips", So print "0".    
*/





#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *child[26];
    bool isEnd;
    Node()
    {
        isEnd=false;
        memset(child,0,sizeof(child));
    }
};
void insert(string s,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        if(!cur->child[idx])
        {
            cur->child[idx]=new Node();
        }
        cur=cur->child[idx];
    }
    cur->isEnd=true;
}
void explore(Node *cur,vector<string> &temp,string s)
{
    Node *q=cur;
    if(cur->isEnd)
    {
        temp.push_back(s);
    }
    for(int i=0;i<26;i++)
    {
        if(q->child[i])
        {
            string w=s;
            w.push_back('a'+i);
            explore(q->child[i],temp,w);
        }
    }
}
void func(Node *root,string s,vector<string> &temp)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        if(!cur->child[idx])
        {
            return ;
        }
        cur=cur->child[idx];
    }
    explore(cur,temp,s);
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
	        insert(str,root);
	    }
	    cin>>str;
	    bool done=false;
	    for(int i=0;i<(str.size());i++)
	    {
	        if(done)
	        {
	            for(int j=i;j<(str.size());j++)
	            {
	                cout<<"0"<<endl;
	            }
	            break;
	        }
	        vector<string> temp;
	        string x;
	        x=str.substr(0,i+1);
	        func(root,x,temp);
	        if(temp.size()==0)
	        {
	            cout<<"0"<<endl;
	            done=true;
	        }else{
	            for(auto it=temp.begin();it!=temp.end();it++)
	            {
	                cout<<(*it)<<" ";
	            }
	            cout<<endl;
	        }
	    }
	}
	return 0;
}






