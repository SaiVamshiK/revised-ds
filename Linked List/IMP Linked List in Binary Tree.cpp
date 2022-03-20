
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the 
binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    bool checkFunc(TreeNode *root,ListNode *head)
    {
        if(head==NULL)
        {
            return true;
        }
        if(root==NULL)
        {
            return false;
        }
        int x1=root->val,x2=head->val;
        if(x1==x2)
        {
            return checkFunc(root->left,head->next)||(checkFunc(root->right,head->next));
        }else{
            return false;
        }
    }
    void func(TreeNode *root,ListNode *head,bool &ans)
    {
        if(root)
        {
            bool check=checkFunc(root,head);
            if(check)
            {
                ans=true;
                return ;
            }
            func(root->left,head,ans);
            if(ans)
            {
                return ;
            }
            func(root->right,head,ans);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)
        {
            return true;
        }
        bool ans=false;
        func(root,head,ans);
        return ans;
    }
};




















