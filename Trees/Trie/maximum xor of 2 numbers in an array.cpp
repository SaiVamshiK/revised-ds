struct Node{
    Node *left;
    Node *right;
    Node()
    {
        left=right=NULL;
    }
};
void insert(Node *root,int x)
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
        if(b==0)
        {
            if(cur->right)
            {
                ans=ans+(pow(2,i));
                cur=cur->right;
            }else{
                cur=cur->left;
            }
        }else{
            if(cur->left)
            {
                ans=ans+pow(2,i);
                cur=cur->left;
            }else{
                cur=cur->right;
            }
        }
    }
    return ans;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        Node *root=new Node();
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            insert(root,a[i]);
        }
        int max_xor=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cur_xor=find(a[i],root);
            max_xor=max(max_xor,cur_xor);
        }
        return max_xor;
    }
};







