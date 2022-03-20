/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. 
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head) 
    {
        if(head==NULL||(head->next==NULL))
        {
            return head;
        }
        unordered_set<int> st;
        Node *cur=head,*prev=head;
        st.insert(cur->data);
        cur=cur->next;
        while(cur)
        {
            int cur_val=cur->data;
            if(st.find(cur_val)==st.end())
            {
                st.insert(cur_val);
                prev=cur;
                cur=cur->next;
            }else{
                prev->next=cur->next;
                cur->next=NULL;
                cur=prev->next;
            }
        }
        return head;
    }
};



