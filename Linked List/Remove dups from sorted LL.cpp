/*
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) 
from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    if(head==NULL||(head->next==NULL))
    {
        return head;
    }
    Node *cur=head;
    while(cur)
    {
        int cur_val=cur->data;
        if(cur->next==NULL)
        {
            break;
        }
        Node *temp=cur;
        while((temp->next)&&(temp->next->data)==cur_val)
        {
            temp=temp->next;
        }
        if(temp==cur)
        {
            cur=cur->next;
            continue;
        }
        cur->next=temp->next;
        temp->next=NULL;
        cur=cur->next;
    }
    return head;
}

