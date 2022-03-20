
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 = m = n = length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version 
of this question. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* func(ListNode *head)
{
    if((!head)||(!head->next))
    {
        return head;
    }
    ListNode *rev=func(head->next);
    head->next->next=head;
    head->next=NULL;
    return rev;
}
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if(m==1)
    {
        ListNode *cur=head;
        int x=n-1;
        while(x--)
        {
            cur=cur->next;
        }
        ListNode *f1=cur->next;
        cur->next=NULL;
        ListNode *temp=func(head);
        ListNode *move=temp;
        while(move->next)
        {
            move=move->next;
        }
        move->next=f1;
        return temp;
    }
    int x=m-2;
    ListNode *f1=head;
    while(x--)
    {
        f1=f1->next;
    }
    int y=n-1;
    ListNode *f2=head;
    while(y--)
    {
        f2=f2->next;
    }
    ListNode *right=f2->next;
    f2->next=NULL;
    ListNode *left=head;
    ListNode *start=f1->next;
    f1->next=NULL;
    ListNode *rev=func(start);
    f1->next=rev;
    ListNode *move=rev;
    while(move->next)
    {
        move=move->next;
    }
    move->next=right;
    return head;
}

