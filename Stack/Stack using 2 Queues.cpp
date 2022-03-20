
Implement a last in first out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {
        while(!q1.empty())
        {
            q1.pop();
        }
        while(!q2.empty())
        {
            q2.pop();
        } 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while((!q1.empty())&&(q1.size()>1))
        {
            int x=q1.front();
            q1.pop();
            q2.push(x);
        }
        int firstVal=q1.front();
        q1.pop();
        swap(q1,q2);
        return firstVal;
    }
    
    /** Get the top element. */
    int top() {
        while((!q1.empty())&&(q1.size()>1))
        {
            int x=q1.front();
            q1.pop();
            q2.push(x);
        }
        int firstVal=q1.front();
        q1.pop();
        q2.push(firstVal);
        swap(q1,q2);
        return firstVal;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};















