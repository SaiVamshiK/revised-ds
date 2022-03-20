






#include <bits/stdc++.h>
using namespace std;
struct Node{
  	unordered_map<char,Node*> mp;
    bool isEnd;
    int wt;
    Node()
    {
        isEnd=false;
        wt=0;
    }
};

void insert(string s,int wt,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        if(!cur->mp[s[i]])
        {
            cur->mp[s[i]]=new Node();
        }
        cur=cur->mp[s[i]];
        if((cur->wt)<wt)
        {
            cur->wt=wt;
        }
    }
    cur->isEnd=true;
}
int search(string s,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        if(!cur->mp[s[i]])
        {
            return -1;
        }
        cur=cur->mp[s[i]];
    }
    return cur->wt;
}
int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    int wt;
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        cin>>s>>wt;
        insert(s,wt,root);
    }
    while(q--)
    {
        cin>>s;
        cout<<search(s,root)<<endl;
    }
    return 0;
}





