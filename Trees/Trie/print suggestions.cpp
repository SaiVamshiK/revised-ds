


/*
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS

1=N=30000
sum(len(string[i]))=2*10^5
1=Q=10^3

INPUT FORMAT

Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user

OUTPUT FORMAT

If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase

SAMPLE INPUT

3
fact
factorial
factory
2
fact
pradyumn

SAMPLE OUTPUT

fact
factorial
factory
No suggestions


*/


#include <bits/stdc++.h>
using namespace std;
struct Node{
  	bool isEnd;
    Node *child[26];
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
void explore(Node *cur,string temp)
{
    if(cur==NULL) return ;
    if(cur->isEnd)
    {
        cout<<temp<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(cur->child[i])
        {
         	string q=temp;
            char x='a'+i;
            q.push_back(x);
            explore(cur->child[i],q);   
        }
    }
}
void search(string s,Node *root,bool &ans)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        if(!cur->child[idx])
        {
            ans=false;
            return ;
        }
        cur=cur->child[idx];
    }
    ans=true;
    string temp=s;
    explore(cur,temp);
    
}
int main()
{
    int n;
    cin>>n;
    string s;
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        cin>>s;
        insert(s,root);
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>s;
        bool ans=true;
        search(s,root,ans);
        if(!ans)
        {
            insert(s,root);
            cout<<"No suggestions"<<endl;
        }
    }
    return 0;
}








