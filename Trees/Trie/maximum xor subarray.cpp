




#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *left;
    Node *right;
};
void insert(int x,Node *root)
{
    Node *cur=root;
    for(int i=31;i>=0;i--)
    {
        int b=(x>>i)&1;
        if(b==0)
        {
            if(!cur->left)
            {
                cur->left=new Node();
            }
            cur=cur->left;
        }else{
            if(!cur->right)
            {
                cur->right=new Node();
            }
            cur=cur->right;
        }
    }
}
int find(int x,Node *root)
{
    int ans=0;
    Node *cur=root;
    for(int i=31;i>=0;i--)
    {
        int b=(x>>i)&1;
        if(b==0){
            if(cur->right)
            {
                cur=cur->right;
                ans=ans+(pow(2,i));
            }else{
                cur=cur->left;
            }
        }else{
            if(cur->left)
            {
                cur=cur->left;
                ans=ans+(pow(2,i));
            }else{
                cur=cur->right;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cur=a[0];
    int ans=a[0];
    insert(cur,root);
    for(int i=1;i<n;i++)
    {
		cur=cur^(a[i]);
        insert(cur,root);
        ans=max(ans,cur);
        ans=max(ans,find(cur,root));
    }
    cout<<ans<<endl;
}













