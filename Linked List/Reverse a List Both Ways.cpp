class Solution
{
    public:
    Node* func(Node *head)
    {
        if(head==NULL||(head->next==NULL))
        {
            return head;
        }
        Node *temp=func(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    struct Node* reverseList(struct Node *head)
    {
        return func(head);
    }
    
};


class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL||(head->next==NULL))
        {
            return head;
        }
        Node *prev=NULL,*cur=head,*next=head->next;
        while(true)
        {
            cur->next=prev;
            prev=cur;
            cur=next;
            if(cur==NULL)
            {
                break;
            }
            next=next->next;
        }
        return prev;
    }
    
};
 
