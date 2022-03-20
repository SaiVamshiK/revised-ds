
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -8.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

The Algo:
	for an element at index i to be peak a[i]>a[i-1] and a[i]>a[i+1]
	if the above condition satisfies then we would return i
	if not one of the above conditions must have failed 
	if a[i]<a[i-1] i.e. first condition failed then we move left
	Reason for moving left:
		We are sure that if a[i-1]>a[i] then one peak element would definetely exist on the left side. (dry run it)
	if a[i]<a[i+1] i.e. second condition failed then we move right
	Reason for moving right:
		if a[i]<a[i+1] then we are definetely sure that one peak element would be present in the right side . (dry run it)
	if both conditions fail then move either to left or right which means we are sure that definetely one peak element would exist on both sides.

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        if(n==1)
        {
            return 0;
        }
        if(n==2)
        {
            if(a[0]>a[1])
            {
                return 0;
            }else{
                return 1;
            }
        }
        if(a[0]>a[1])
        {
            return 0;
        }
        if(a[n-1]>a[n-2])
        {
            return n-1;
        }
        int start=1,end=n-2;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(a[mid]>a[mid-1]&&(a[mid]>a[mid+1]))
            {
                return mid;
            }
            if(a[mid]<a[mid-1])
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
};
