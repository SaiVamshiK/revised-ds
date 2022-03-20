
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. 
The order of appearance of numbers within each segregation should be same as that in the original list.


Example 1:

Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear 
first and 2,4,6 are the even numbers that appear later.

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
class Solution{
public:
    Node* divide(int n, Node *head){
        if(head==NULL||(head->next==NULL))
        {
            return head;
        }
        Node *cur=head;
        vector<int> even,odd;
        while(cur)
        {
            int x=cur->data;
            if(x%2==0)
            {
                even.push_back(x);
            }else{
                odd.push_back(x);
            }
            cur=cur->next;
        }
        cur=head;
        for(int i=0;i<(even.size());i++)
        {
            cur->data=even[i];
            cur=cur->next;
        }
        for(int i=0;i<(odd.size());i++)
        {
            cur->data=odd[i];
            cur=cur->next;
        }
        return head;
    }
};

