struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node *left,Node *right)
    {
        if(left==NULL&&(right!=NULL))
        {
            return right;
        }
        if(left!=NULL&&(right==NULL))
        {
            return left;
        }
        if(left==NULL&&(right==NULL))
        {
            return NULL;
        }
        int left_val=(left->data),right_val=(right->data);
        if(left_val<=right_val)
        {
            Node *head=new Node(left_val);
            head->next=merge(left->next,right);
            return head;
        }else{
            Node *head=new Node(right_val);
            head->next=merge(left,right->next);
            return head;
        }
    }
    Node* MS(Node *head)
    {
        if(head==NULL||(head->next==NULL))
        {
            return head;
        }
        Node *sp=head,*fp=head,*pre=NULL;
        while(fp&&(fp->next))
        {
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        pre->next=NULL;
        Node *left=MS(head);
        Node *right=MS(sp);
        return merge(left,right);
    }
    Node* mergeSort(Node* head) {
        return MS(head);
    }
};

