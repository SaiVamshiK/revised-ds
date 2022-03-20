
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
pair<string,int> func(Node *root,unordered_map<string,int> &mp,bool &done)
{
    if(root==NULL)
    {
        return {"n",0};
    }
    pair<string,int> left=func(root->left,mp,done);
    pair<string,int> right=func(root->right,mp,done);
    char d=root->data;
    string ans=to_string(d)+"."+left.first+"."+right.first;
    mp[ans]++;
    if(mp[ans]==2)
    {
        if((left.second+right.second+1)>=2)
        {
            done=true;
        }
    }
    return {ans,left.second+right.second+1};
}
bool dupSub(Node *root)
{
    bool done=false;
    unordered_map<string,int> mp;
    func(root,mp,done);
    return done;
}



