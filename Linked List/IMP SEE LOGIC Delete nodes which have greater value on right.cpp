
Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on their next node. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* rev(Node *head)
    {
        if((!head)||(!head->next))
        {
            return head;
        }
        Node *smallAns=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallAns;
    }
    Node *compute(Node *h)
    {
        if((!h)||(!h->next))
        {
            return h;
        }
        Node *head=rev(h);
        Node *cur=head;
        int maxVal=(cur->data);
        Node *prev=cur;
        cur=cur->next;
        while(cur)
        {
            int cur_val=(cur->data);
            if(cur_val<maxVal)
            {
                prev->next=cur->next;
                cur->next=NULL;
                cur=prev->next;
            }else{
                prev=cur;
                cur=cur->next;
                maxVal=max(maxVal,cur_val);
            }
        }
        return rev(head);
    }
    
};
   
   
