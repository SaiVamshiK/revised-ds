
Given the head of a singly linked list, return true if it is a palindrome.

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||(head->next==NULL))
        {
            return true;
        }
        ListNode *sp=head,*fp=head,*prev=NULL;
        while(fp&&(fp->next))
        {
            prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        if(fp)
        {
            stack<int> st;
            ListNode *p1=head;
            while(p1!=(prev->next))
            {
                st.push(p1->val);
                p1=p1->next;
            }
            p1=sp->next;
            while(p1)
            {
                int val=(p1->val);
                if(val!=st.top())
                {
                    return false;
                }
                st.pop();
                p1=p1->next;
            }
        }else{
            stack<int> st;
            ListNode *p1=head;
            while(p1!=(prev->next))
            {
                st.push(p1->val);
                p1=p1->next;
            }
            p1=sp;
            while(p1)
            {
                int val=(p1->val);
                if(val!=st.top())
                {
                    return false;
                }
                st.pop();
                p1=p1->next;
            }
        }
        return true;
    }
};
