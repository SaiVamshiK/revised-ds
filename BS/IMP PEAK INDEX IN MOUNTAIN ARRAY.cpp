
Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            int left=mid-1,right=mid+1;
            if((left>=0)&&(a[mid]>a[left])&&(right<n)&&(a[mid]>a[right]))
            {
                return mid;
            }
            if((left>=0)&&(a[mid]<a[left]))
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
};
