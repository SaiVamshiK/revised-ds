


/*
Example:
Input:
2
8
Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
HA
3
WelcomeGeek WelcomeToGeeksForGeeks GeeksForGeeks
WTG

Output:
No match found
WelcomeToGeeksForGeeks
*/



#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *child[26];
    bool isEnd;
    vector<string> vec;
    Node(){
        memset(child,0,sizeof(child));
        isEnd=false;
    }
};
bool isCapital(char ch)
{
    if((ch>='A')&&(ch<='Z'))
    {
        return true;
    }
    return false;
}
void insert(string temp,string s,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(temp.size());i++)
    {
        int idx=temp[i]-'A';
        if(!cur->child[idx])
        {
            cur->child[idx]=new Node();
        }
        cur=cur->child[idx];
    }
    cur->isEnd=true;
    cur->vec.push_back(s);
}
void explore(Node *root)
{
    if(root->isEnd)
    {
        for(int i=0;i<((root->vec).size());i++)
        {
            cout<<(root->vec[i])<<' ';
        }
    }
    for(int i=0;i<26;i++)
    {
        if(root->child[i])
        {
            explore(root->child[i]);
        }
    }
}
void solve(string s,Node *root,bool &done)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'A';
        if(!cur->child[idx])
        {
            done=false;
            return ;
        }
        cur=cur->child[idx];
    }
    explore(cur);
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
	        string temp="";
	        for(int j=0;j<(str.size());j++)
	        {
	            if(isCapital(str[j]))
	            {
	                temp.push_back(str[j]);
	            }
	        }
	        //cout<<"Temp:"<<temp<<endl;
	        insert(temp,str,root);
	    }
	    cin>>str;
	    bool done=true;
	    solve(str,root,done);
	    if(!done)
	    {
	        cout<<"No match found"<<endl;
	    }else{
	        cout<<endl;
	    }
	}
	return 0;
}






