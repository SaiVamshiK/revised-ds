You will be given a stream of numbers, and you need to find the kth largest number in the stream at any given time.
As the stream of numbers can not be given during compile time, so you need to design a data structure which can accept infinite numbers and can return the kth largest number at any given time.
The stream of numbers is nothing but a large collection of numbers from which integers are read at runtime, such as the user will never know the upper limit on the number of integers which will be read.
The implemented data structure must support the following operations:
1. add(data) :
   This function should take one argument of type integer 
   and store it in its pool.
2. int getKthLargest() :
   This function should return the kth largest number from 
   the current pool of integers.
   
#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int max_size;
    Kthlargest(int k, vector<int> &arr) {
       max_size=k;
       for(int i=0;i<(arr.size());i++)
       {
           pq.push(arr[i]);
       }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>max_size)
        {
            pq.pop();
        }
    }

    int getKthLargest() {
       return pq.top();
    }

};
