/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *child;
        vector<TreeNode<T> *> child;
	    TreeNode(T data)
	    {
		    this->data = data;
		    child = new vector<TreeNode<T> *>;
	    }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> ans;
    if(!root)
    {
        return ans;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            TreeNode<int> *cur=q.front();
            q.pop();
            ans.push_back(cur->data);
            for(int i=0;i<(cur->child.size());i++)
            {
                TreeNode<int> *pushNode=cur->child[i];
                q.push(pushNode);
            }
        }
    }
    return ans;
}
















