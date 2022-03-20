/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

Algo Is IMp:
	SImilar to merge 2 sorted lists here generalize and maintain k pointers instead of 2 pointers

typedef pair<int,ListNode*> pi;
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<(A.size());i++)
    {
        pq.push({A[i]->val,A[i]});
    }
    ListNode *root=new ListNode(-1);
    ListNode *ans=root;
    while(!pq.empty())
    {
        pi temp=pq.top();
        pq.pop();
        root->next=new ListNode(temp.first);
        root=root->next;
        ListNode *cur=temp.second;
        cur=cur->next;
        if(cur)
        {
            pq.push({cur->val,cur});
        }
    }
    return ans->next;
}

