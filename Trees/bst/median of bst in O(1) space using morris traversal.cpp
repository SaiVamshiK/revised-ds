
/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
int morrisTraversal(Node *root,int n1)
{
    int cnt=0;
    Node *cur=root;
    while(cur)
    {
        if(cur->left==NULL)
        {
            cnt++;
            if(cnt==n1)
            {
                return (cur->data);
            }
            cur=cur->right;
        }else{
            Node *temp=cur->left;
            while(temp->right&&(temp->right!=cur))
            {
                temp=temp->right;
            }
            if(temp->right==cur)
            {
                cnt++;
                if(cnt==n1)
                {
                    return (cur->data);
                }
                temp->right=NULL;
                cur=cur->right;
            }else{
                temp->right=cur;
                cur=cur->left;
            }
        }
    }
    return cnt;
}
float morrisTraversal1(Node *root,int n1,int n2)
{
    int cnt=0;
    Node *cur=root;
    int ans1=INT_MIN,ans2=INT_MIN;
    while(cur)
    {
        if(cur->left==NULL)
        {
            cnt++;
            if(cnt==n1)
            {
                ans1=(cur->data);
            }
            if(cnt==n2)
            {
                ans2=(cur->data);
                return float(ans1+ans2)/2;
            }
            cur=cur->right;
        }else{
            Node *temp=cur->left;
            while(temp->right&&(temp->right!=cur))
            {
                temp=temp->right;
            }
            if(temp->right==cur)
            {
                cnt++;
                if(cnt==n1)
                {
                    ans1=(cur->data);
                }
                if(cnt==n2)
                {
                    ans2=(cur->data);
                    return float(ans1+ans2)/2;
                }
                temp->right=NULL;
                cur=cur->right;
            }else{
                temp->right=cur;
                cur=cur->left;
            }
        }
    }
    return cnt;
}
float findMedian(struct Node *root)
{
    int n=morrisTraversal(root,INT_MIN);
    if(n%2!=0)
    {
        return morrisTraversal(root,(n/2)+1);
    }else{
        return morrisTraversal1(root,(n/2),(n/2)+1);
    }
}



