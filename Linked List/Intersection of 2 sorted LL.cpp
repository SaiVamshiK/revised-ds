/* The structure of the Linked list Node is as follows:

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. 
The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *ans=new Node(-1);
    Node *lastPtr=ans;
    Node *h1=head1,*h2=head2;
    while(h1&&(h2))
    {
        int v1=(h1->data),v2=(h2->data);
        if(v1==v2)
        {
            Node *temp=new Node(v1);
            lastPtr->next=temp;
            lastPtr=lastPtr->next;
            h1=h1->next;
            h2=h2->next;
        }
        else if(v1>v2)
        {
            h2=h2->next;
        }else{
            h1=h1->next;
        }
    }
    return ans->next;
}



