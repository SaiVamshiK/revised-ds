
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int > s1,s2;
    MyQueue() {
        while((!s1.empty()))
        {
            s1.pop();
        }
        while(!s2.empty())
        {
            s2.pop();
        } 
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty())
        {
            int x=s1.top();
            s1.pop();
            s2.push(x);
        }
        int ret=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            int x=s2.top();
            s1.push(x);
            s2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s1.empty())
        {
            int x=s1.top();
            s1.pop();
            s2.push(x);
        }
        int ret=s2.top();
        while(!s2.empty())
        {
            int x=s2.top();
            s1.push(x);
            s2.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
