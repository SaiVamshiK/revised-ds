
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(k==0||(!head)||(!head->next))
    {
        return head;
    }
    int n=0;
    ListNode *cur=head;
    while(cur)
    {
        n++;
        cur=cur->next;
    }
    if(k%n==0)
    {
        return head;
    }
    k=k%n;
    n=n-k-1;
    cur=head;
    while(n--)
    {
        cur=cur->next;
    }
    ListNode *next=cur->next;
    ListNode *ans=next;
    cur->next=NULL;
    while(next->next)
    {
        next=next->next;
    }
    next->next=head;
    return ans;
}

