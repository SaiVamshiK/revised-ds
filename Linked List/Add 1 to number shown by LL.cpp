

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 

/* 

struct Node
{
    int data;
    struct Node* next;
    
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
        Node *temp=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    Node* addOne(Node *h) 
    {
        Node *head=rev(h);
        Node *cur=head;
        while(true)
        {
            int x=(cur->data)+1;
            if(x>9)
            {
                cur->data=0;
                if((cur->next)==NULL)
                {
                    cur->next=new Node(1);
                    break;
                }else{
                    cur=cur->next;
                }
            }else{
                cur->data=x;
                break;   
            }
        }
        return rev(head);
    }
};
