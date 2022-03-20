
Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.

Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2


Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* rev(ListNode *head)
{
    if((!head)||(!head->next))
    {
        return head;
    }
    ListNode *temp=rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
ListNode* func(ListNode *head,int k)
{
    if((!head))
    {
        return head;
    }
    int x=k-1;
    ListNode *cur=head;
    while(x--)
    {
        cur=cur->next;
    }
    ListNode *next_k_starting=cur->next;
    cur->next=NULL;
    ListNode *fst_k_rev=rev(head);
    x=k-1;
    if(next_k_starting==NULL)
    {
        return fst_k_rev;
    }else{
        ListNode *move_k=next_k_starting;
        while(x--)
        {
            move_k=move_k->next;
        }
        ListNode *next=move_k->next;
        move_k->next=NULL;
        ListNode *smallAns=func(next,k);
        move_k->next=smallAns;
        ListNode *rev_move=fst_k_rev;
        while(rev_move->next)
        {
            rev_move=rev_move->next;
        }
        rev_move->next=next_k_starting;
        return fst_k_rev;
    }
}
ListNode* Solution::solve(ListNode* head, int k) {
    if((!head)||(!head->next))
    {
        return head;
    }
    return func(head,k);
}

