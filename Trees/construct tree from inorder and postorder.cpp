/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node* func(int in[],int post[],int ins,int ine,int posts,int poste)
{
    if((ins>ine)||(posts>poste))
    {
        return NULL;
    }
    int x;
    int rootData=post[poste];
    for(int i=ins;i<=ine;i++)
    {
        if(in[i]==rootData)
        {
            x=i;
            break;
        }
    }
    Node *root=new Node(post[poste]);
    int lins=ins;
    int line=x-1;
    int lposts=posts;
    int lposte=line-lins+lposts;
    int rins=x+1;
    int rine=ine;
    int rposts=lposte+1;
    int rposte=poste-1;
    root->left=func(in,post,lins,line,lposts,lposte);
    root->right=func(in,post,rins,rine,rposts,rposte);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    return func(in,post,0,n-1,0,n-1);
}


