
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.

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
    TreeNode* func(ListNode *head)
    {
        if((!head))
        {
            return NULL;
        }
        if((!head->next))
        {
            return new TreeNode(head->val);
        }
        ListNode *sp=head,*fp=head,*prev=NULL;
        while((fp)&&(fp->next))
        {
            prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        prev->next=NULL;
        int x=(sp->val);
        ListNode *right_head=sp->next;
        sp->next=NULL;
        TreeNode *root=new TreeNode(x);
        root->left=func(head);
        root->right=func(right_head);
        return root; 
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return func(head);
    }
};







