
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is 
connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *sp=head,*fp=head;
        while(fp&&(fp->next))
        {
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp)
            {
                if(sp==head)
                {
                    return sp;
                }
                sp=head;
                while(sp->next!=(fp->next))
                {
                    sp=sp->next;
                    fp=fp->next;
                }
                return sp->next;
            }
        }
        return NULL;
    }
};
