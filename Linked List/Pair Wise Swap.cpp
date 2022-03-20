
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *func(ListNode *head)
{
    if((!head)||(!head->next))
    {
        return head;
    }
    ListNode *temp=head->next->next;
    head->next->next=NULL;
    ListNode *smallAns=func(temp);
    ListNode *x=head->next;
    head->next=NULL;
    x->next=head;
    head->next=smallAns;
    return x;
}
ListNode* Solution::swapPairs(ListNode* head) {
    if((!head)&&(!head->next)&&(!head->next->next)&&(!head->next->next->next))
    {
        return head;
    }
    return func(head);
}

