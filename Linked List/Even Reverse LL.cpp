
Problem Description

Given a linked list A , reverse the order of all nodes at even positions.

Example Input
Input 1:

A = 1 -> 2 -> 3 -> 4
Input 2:

A = 1 -> 2 -> 3


Example Output
Output 1:

 1 -> 4 -> 3 -> 2
Output 2:

 1 -> 2 -> 3


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) {
    if((!head)||(!head->next)||(!head->next->next)||(!head->next->next->next))
    {
        return head;
    }
    vector<int> v;
    ListNode *cur=head;
    cur=cur->next;
    while(cur)
    {
        v.push_back(cur->val);
        cur=cur->next;
        if(cur)
        {
            cur=cur->next;
        }
    }
    cur=head->next;
    reverse(v.begin(),v.end());
    for(int i=0;i<(v.size());i++)
    {
        cur->val=v[i];
        cur=cur->next;
        if(cur)
        {
            cur=cur->next;
        }
    }
    return head;
}

