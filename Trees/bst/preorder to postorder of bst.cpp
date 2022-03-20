#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        data=v;
        left=NULL;
        right=NULL;
    }
};
void postorder(Node *root)
{
    if(root==NULL) 
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';
}
Node* func(int *inp,int l,int r)
{
    if(l>r)
    {
        return NULL;
    }
    Node *root=new Node(inp[l]);
    int x=-1;
    for(int i=l+1;i<=r;i++)
    {
        if(inp[i]>inp[l])
        {
            x=i;
            break;
        }
    }
    if(x==-1)
    {
    	root->right=NULL;
    	root->left=func(inp,l+1,r);
    	return root;
	}
    root->left=func(inp,l+1,x-1);
    root->right=func(inp,x,r);
    return root;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int *inp=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>inp[i];
	    }
	    Node *root=func(inp,0,n-1);
	    postorder(root);
	    cout<<endl;
	}
	return 0;
}
