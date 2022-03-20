
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1

*************************		Heart of the problem is pushing 2*x-minElem		*************************

let, y= new_min_element
let, x= old_min_element
so:  y<x       (as newer min element is lesser than older min element)
adding y to both sides
=====>   2*y<x+y
subtracting x from both sides 
=====> 2*y-x<y
this proves that 2*y-x will always be lesser than the curr_minimum_element or new_min

Hence 2*x-curr_min always works as a flag here

Also, with the approach above, you could have derived any other valid formula of your own.


stack<int> st;
int minElem;
MinStack::MinStack() {
    while(!st.empty())
    {
        st.pop();
    }
    minElem=INT_MAX;
}

void MinStack::push(int x) {
    if(st.empty())
    {
        st.push(x);
        minElem=x;
    }else{
        if(x>=minElem)
        {
            st.push(x);
        }else{
            int temp=minElem;
            minElem=x;
            st.push(2*x-(temp));
        }
    }
}

void MinStack::pop() {
    if(!st.empty())
    {
        int topElem=st.top();
        st.pop();
        if(topElem<minElem)
        {
            minElem=(2*minElem)-topElem;
        }
    }
}

int MinStack::top() {
    if(!st.empty())
    {
        if(st.top()<minElem)
        {
            return minElem;
        }
        return st.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(st.empty())
    {
        return -1;
    }
    return minElem;
}


