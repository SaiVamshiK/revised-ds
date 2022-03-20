Node* insert(Node* root, int key)
{
    if(root==NULL)
    {
        return new Node(key);
    }
    if(root->data<key)
    {
        root->right=insert(root->right,key);
    }else if(root->data==key)
    {
        return root;
    }
    else{
        root->left=insert(root->left,key);
    }
}





