
Example:
Input:
1
5
abracadabra
geeksforgeeks
abracadabra
geeks
geeksthrill
5
abr
geeks
geeksforgeeks
ge
gar

Output:
2
3
1
3
0

Explanation:

There are 2 strings that have prefix "abr" - "abracadabra" and "abracadabra"
There are 3 strings that have prefix "geeks" - "geeksforgeeks" and "geeks" and "geeksthrill"
There is 1 string thathave prefix "geeksforgeeks" - "geeksforgeeks".
There are 3 strings that have prefix "ge" - "geeksforgeeks" and "geeks" and "geeksthrill"
There is No string thathave prefix as "gar".

#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *child[26];
    bool isEnd;
    int cnt;
    Node()
    {
        memset(child,0,sizeof(child));
        isEnd=false;
        cnt=0;
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
        cur->cnt++;
    }
    cur->isEnd=true;
}
int find(string s,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        if(!cur->child[idx])
        {
            return 0;
        }
        cur=cur->child[idx];
    }
    return cur->cnt;
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
	    int q;
	    cin>>q;
	    while(q--)
	    {
	        cin>>str;
	        cout<<find(str,root)<<endl;
	    }
	}
	return 0;
}
