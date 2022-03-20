

SAMPLE INPUT

2 1
hackerearth 10
hackerrank 9
hacker

SAMPLE OUTPUT

10




#include <bits/stdc++.h>
using namespace std;
struct Node{
  	bool isEnd;
    unordered_map<char,Node*> mp;
    int wt;
    Node()
    {
        wt=-1;
        isEnd=false;
    }
};
void insert(string s,Node *root,int wt)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        if(!cur->mp[s[i]])
        {
            cur->mp[s[i]]=new Node();
        }
        cur=cur->mp[s[i]];
    }
    cur->isEnd=true;
    cur->wt=wt;
}
void search(string s,Node *root,Node* &ans)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        if(!cur->mp[s[i]])
        {
            ans=NULL;
            return ;
        }
        cur=cur->mp[s[i]];
    }
    ans=cur;
}

void explore(Node *root,int &max_wt)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->isEnd&&((root->wt)>max_wt))
    {
        max_wt=root->wt;
    }
    unordered_map<char,Node*> temp=root->mp;
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        explore(it->second,max_wt);
    }
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
        insert(s,root,wt);
    }    
    while(q--)
    {
        cin>>s;
        Node *cur;
        search(s,root,cur);
        if(!cur)
        {
            cout<<-1<<endl;
        }else{
            int max_wt=-1;
            explore(cur,max_wt);
            cout<<max_wt<<endl;
        }
    }
    return 0;
}



