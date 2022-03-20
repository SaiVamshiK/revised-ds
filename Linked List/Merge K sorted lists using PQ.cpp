
Given K sorted linked lists of different sizes. 
The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.

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
typedef pair<int,Node*> pi;

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *a[], int k)
    {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({a[i]->data,a[i]});
        }
        Node *head=new Node(-1);
        Node *ans=head;
        while(!pq.empty())
        {
            pi temp=pq.top();
            pq.pop();
            head->next=new Node(temp.first);
            head=head->next;
            if(temp.second->next)
            {
                pq.push({temp.second->next->data,temp.second->next});
            }
        }
        return ans->next;
    }
};

