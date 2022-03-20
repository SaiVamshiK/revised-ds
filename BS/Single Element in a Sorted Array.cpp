
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one 
element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1)
        {
            return a[0];
        }
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            int cur=a[mid];
            if((mid-1>=0)&&(mid+1<n))
            {
                if(a[mid-1]!=cur&&(a[mid+1]!=cur))
                {
                    return cur;
                }
            }else if((mid-1>=0)){
                if((a[mid-1]!=cur))   
                {
                    return cur;
                }
            }else if((mid+1<n))
            {
                if(a[mid+1]!=cur)
                {
                    return cur;
                }
            }
            if((mid-1>=0)&&(a[mid-1]==cur))
            {
                int leftSize=(mid-start-1);
                if(leftSize%2==0)
                {
                    start=mid+1;
                }else{
                    end=mid-2;
                }
            }else if((mid+1<n)&&(a[mid+1]==cur))
            {
                int leftSize=mid-start;
                if(leftSize%2!=0)
                {
                    end=mid-1;
                }else{
                    start=mid+2;
                }
            }
        }
        return -1;
    }
};
