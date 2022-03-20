
Problem Description

Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.

Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 1 6 -> 15 -> 61 -> 16
 B = 3
Input 2:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 2
Input 3:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 10


Example Output
Output 1:

 4
Output 2:

 14
Output 3:

 -1


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* head, int k) {
    int n=0;
    ListNode *cur=head;
    while(cur)
    {
        n++;
        cur=cur->next;
    }
    int x=(n/2)+1;
    x--;
    x=x-k;
    if(x<0)
    {
        return -1;
    }
    cur=head;
    while(x--)
    {
        cur=cur->next;
    }
    return cur->val;
}

