

Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an 
additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the 
functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.

# USING EXTRA SPACE

stack<int> helperStack; 
void push(stack<int>& s, int a){
    s.push(a);
	if(helperStack.empty())
	{
	    helperStack.push(a);
	}else{
		*******************************			here <= is imp for dups handling					*******************************
	    if(helperStack.top()>=a)
	    {
	        helperStack.push(a);
	    }
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n)
	{
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
    int elem=s.top();
    s.pop();
	if(!helperStack.empty())
	{
	    if(helperStack.top()==elem)
	    {
	        helperStack.pop();
	    }
	}
	return elem;
}

int getMin(stack<int>& s){
	if(!helperStack.empty())
	{
	    return helperStack.top();
	}
	return -1;
}

