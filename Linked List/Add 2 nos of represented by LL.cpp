
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1=l1,*h2=l2;
        ListNode *ans=new ListNode(-1);
        ListNode *fin=ans;
        int carryVal=0;
        while(h1&&(h2))
        {
            int x1=(h1->val),x2=(h2->val);
            int temp=(x1+x2+carryVal);
            ans->next=new ListNode(temp%10);
            carryVal=temp/10;
            ans=ans->next;
            h1=h1->next;
            h2=h2->next;
        }
        while(h1)
        {
            int x1=(h1->val);
            int temp=(x1+carryVal);
            ans->next=new ListNode(temp%10);
            carryVal=temp/10;
            ans=ans->next;
            h1=h1->next;
        }
        while(h2){
            int x2=(h2->val);
            int temp=(x2+carryVal);
            ans->next=new ListNode(temp%10);
            carryVal=temp/10;
            ans=ans->next;
            h2=h2->next;
        }
        if(carryVal!=0)
        {
            ans->next=new ListNode(carryVal);
        }
        return fin->next;
    }
};





