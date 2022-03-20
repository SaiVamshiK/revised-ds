
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* root, int k) {
    if(root==NULL)
    {
        return root;
    }
    int n=0;
    ListNode *cur=root;
    while(cur)
    {
        n++;
        cur=cur->next;
    }
    n=n-k-1;
    if(n<0)
    {
        return root->next;
    }
    cur=root;
    while(n--)
    {
        cur=cur->next;
    }
    ListNode *temp=cur->next;
    cur->next=temp->next;
    temp->next=NULL;
    return root;
}

