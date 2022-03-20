
Given the head of a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1,v2;
        ListNode *cur=head;
        while(cur)
        {
            int v=(cur->val);
            if(v<x)
            {
                v1.push_back(v);
            }else{
                v2.push_back(v);
            }
            cur=cur->next;
        }
        cur=head;
        for(int i=0;i<(v1.size());i++)
        {
            cur->val=v1[i];
            cur=cur->next;
        }
        for(int i=0;i<(v2.size());i++)
        {
            cur->val=v2[i];
            cur=cur->next;
        }
        return head;
    }
};





