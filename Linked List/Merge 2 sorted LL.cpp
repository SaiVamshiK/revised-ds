/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    if(a==NULL&&(b!=NULL))
    {
        return b;
    }
    if(a!=NULL&&(b==NULL))
    {
        return a;
    }
    if(a==NULL&&(b==NULL))
    {
        return NULL;
    }
    ListNode *root;
    int left_val=(a->val),right_val=(b->val);
    if(left_val<=right_val)
    {
        root=new ListNode(left_val);
        root->next=mergeTwoLists(a->next,b);
        return root;
    }else{
        root=new ListNode(right_val);
        root->next=mergeTwoLists(a,b->next);
        return root;
    }
}

