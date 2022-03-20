/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Given a singly linked list and an integer K, reverses the nodes of the
//
//list K at a time and returns modified linked list.
//
// NOTE : The length of the list is divisible by K 
//Example :
//
//Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
//
//You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
//
//Try to solve the problem using constant extra space.


ListNode* func(ListNode *head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    ListNode *cur=head;
    int temp=k-1;
    while(temp--)
    {
        cur=cur->next;
    }
    ListNode *nextPtr=cur->next;
    cur->next=NULL;
    ListNode *smallAns=func(nextPtr,k);
    ListNode *prev=NULL,*currPtr=head,*next=head->next;
    while(true)
    {
        currPtr->next=prev;
        prev=currPtr;
        currPtr=next;
        if(currPtr==NULL)
        {
            break;
        }
        next=next->next;
    }
    head->next=smallAns;
    return prev;
}
ListNode* Solution::reverseList(ListNode* head, int k) {
    if(head==NULL||(head->next==NULL))
    {
        return head;
    }
    return func(head,k);
}

