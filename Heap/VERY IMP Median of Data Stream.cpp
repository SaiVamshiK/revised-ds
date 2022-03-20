

Given an input stream of N integers. The task is to insert these numbers into a new stream and 
find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 

priority_queue<int> maxH;
priority_queue<int,vector<int>,greater<int>> minH;
public:
//Function to insert heap.
void insertHeap(int &x)
{
    int h1=maxH.size(),h2=minH.size();
    if(h1==h2)
    {
        if(h1==0)
        {
            maxH.push(x);
        }else{
            if(x<=maxH.top())
            {
                maxH.push(x);
            }else{
                minH.push(x);
            }
        }
    }else{
        if(h1>h2)
        {
            int maxElem=maxH.top();
            if(x<=maxElem)
            {
                int temp=maxH.top();
                maxH.pop();
                minH.push(temp);
                maxH.push(x);
            }else{
                minH.push(x);
            }
        }else if(h2>h1)
        {
            int minElem=minH.top();
            if(x>=minElem)
            {
                int temp=minH.top();
                minH.pop();
                maxH.push(temp);
                minH.push(x);
            }else{
                maxH.push(x);
            }
        }
    }
}


class Solution
{
    public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
    void balanceHeaps()
    {
        if(max_heap.size()>min_heap.size())
        {
            int elem=max_heap.top();
            max_heap.pop();
            min_heap.push(elem);
        }else{
            int elem=min_heap.top();
            min_heap.pop();
            max_heap.push(elem);
        }
    }
    
    //Function to insert heap
    void insertHeap(int &x)
    {
        if(max_heap.empty()&&(min_heap.empty()))
        {
            max_heap.push(x);
            return ;
        }
        int left_max=max_heap.top();
        if(x<=left_max)
        {
            max_heap.push(x);
            if((abs(max_heap.size()-min_heap.size()))>1)
            {
                balanceHeaps();
            }
        }else{
            min_heap.push(x);
            if((abs(max_heap.size()-min_heap.size()))>1)
            {
                balanceHeaps();
            }
        }
    }
    
    //Function to balance heaps.
    
    //Function to return Median.
    double getMedian()
    {
        int h1=max_heap.size(),h2=min_heap.size();
        if(h1==h2)
        {
            return double(((double(max_heap.top()))+(double(min_heap.top())))/2);
        }else{
            if(h1>h2)
            {
                return double(max_heap.top());
            }else{
                return double(min_heap.top());
            }
        }
    }
};
