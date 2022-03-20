#include<bits/stdc++.h>
using namespace std;
struct Node{
  	Node *left;
    Node *right;
    Node()
    {
        left=right=NULL;
    }
};
void insert(Node *root,int val)
{
    Node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int temp=((1<<i)&val);
        if(temp==0)
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
int findMax(Node *root,int val)
{
    Node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int temp=((1<<i)&val);
        if(temp==0)
        {
            if(cur->right)
            {
                ans+=(pow(2,i));
                cur=cur->right;
            }else{
                cur=cur->left;
            }
        }else{
            if(cur->left)
            {
                ans+=pow(2,i);
                cur=cur->left;
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
    int ans=INT_MIN;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    Node *root=new Node();
    insert(root,a[0]);
    for(int i=1;i<n;i++)
    {
        a[i]=a[i]^a[i-1];
        insert(root,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans=max(ans,findMax(root,a[i]));
    }
    cout<<ans;
}
















