








/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node* func(int in[],int pre[],int ins,int ine,int pres,int pree)
{
    if((ine<ins)||(pree<pres))
    {
        return NULL;
    }
    int x;
    int rootData=pre[pres];
    for(int i=ins;i<=ine;i++)
    {
        if(rootData==in[i])
        {
            x=i;
            break;
        }
    }
    int lins=ins;
    int line=x-1;
    int lpres=pres+1;
    int lpree=line-lins+lpres;
    int rins=x+1;
    int rine=ine;
    int rpres=lpree+1;
    int rpree=pree;
    Node *root=new Node(pre[pres]);
    root->left=func(in,pre,lins,line,lpres,lpree);
    root->right=func(in,pre,rins,rine,rpres,rpree);
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    return func(in,pre,0,n-1,0,n-1);
}









