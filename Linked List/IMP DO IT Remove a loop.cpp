

https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head==NULL||(head->next==NULL))
        {
            return ;
        }
        Node *slow=head,*fast=head;
        while((fast)&&(fast->next))
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
            	// IMP Edge Case if both the slow and the fast pointers converge at the head of the LL, then
            	// handle things in a diff way
                if(slow==head)
                { 
                    while(fast->next!=slow)
                    {
                        fast=fast->next;
                    }
                    fast->next=NULL;
                    return ;
                }
                slow=head;
                while((slow->next)!=(fast->next))
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                fast->next=NULL;
            }
        }
    }
};
