
Given a singly linked list

    L: L0 ? L1 ? … ? Ln-1 ? Ln,
reorder it to:

    L0 ? Ln ? L1 ? Ln-1 ? L2 ? Ln-2 ? …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    if((!head)||(!head->next)){
        return head;
    }
    ListNode *temp=rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
ListNode* Solution::reorderList(ListNode* head) {
    if((!head)||(!head->next)||(!head->next->next))
    {
        return head;
    }
    ListNode *sp=head,*fp=head,*prev=NULL;
    while(fp&&(fp->next))
    {
        prev=sp;
        sp=sp->next;
        fp=fp->next->next;
    }
    prev->next=NULL;
    ListNode *ans=head;
    ListNode *h1=head;
    ListNode *h2=rev(sp);
    ListNode *x;
    while((h1)&&(h2))
    {
        ListNode *t1=h1->next,*t2=h2->next;
        h1->next=h2;
        x=h2;
        h2->next=t1;
        h1=t1;
        h2=t2;
    }
    if(h2)
    {
        x->next=h2;
    }
    return ans;
}

