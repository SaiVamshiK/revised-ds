
void func(Node *root,int cur,int level,map<int,int> &mp)
{
    if(root==NULL)
    {
        if(mp.count(level)==0)
        {
            mp[level]=cur;
        }else{
            if(mp[level]<cur)
            {
                mp[level]=cur;
            }
        }
        return ;
    }
    cur=cur+root->data;
    func(root->left,cur,level+1,mp);
    func(root->right,cur,level+1,mp);
}
int sumOfLongRootToLeafPath(Node* root)
{
    map<int,int> mp;
	func(root,0,0,mp);
	map<int,int>::iterator it=mp.end();
	it--;
	return it->second;
}



