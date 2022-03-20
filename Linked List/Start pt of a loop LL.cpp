
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    ListNode *sp=head,*fp=head;
    while(fp&&(fp->next))
    {
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)
        {
            if(sp==head)
            {
                return head;
            }
            sp=head;
            while(sp->next!=fp->next)
            {
                sp=sp->next;
                fp=fp->next;
            }
            return sp->next;
        }
    }
    return NULL;
}

