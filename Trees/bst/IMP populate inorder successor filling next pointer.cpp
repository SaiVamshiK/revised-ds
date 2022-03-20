/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/
void func(node *p,node* &prev)
{
    if(p==NULL) return ;
    func(p->right,prev);
    p->next=prev;
    prev=p;
    func(p->left,prev);
}
void populateNext(struct node* p)
{
    node *pre=NULL;
    func(p,pre);
}



