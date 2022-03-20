
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:

Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4. 
The original sorted array is 1 2 3 4 5. 
We can see that the array was rotated 
1 times to the right.


class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            if(a[start]<a[end])
            {
                return a[start];
            }
            int mid=start+((end-start)/2);
            int left=((mid-1+n)%n),right=(mid+1)%n;
            if(a[mid]<=a[left]&&(a[mid]<=a[right]))
            {
                return a[mid];
            }
            else if(a[start]<=a[mid])
            {
                start=right;
            }else{
                end=left;
            }
        }
        return -1;
    }
};

class Solution{
public:	
	int findKRotation(int a[], int n) {
	    if(n==0||(n==1))
	    {
	        return 0;
	    }
	    int start=0,end=n-1;
	    while(start<=end)
	    {
	        if(a[start]<a[end])
	        {
	            return start;
	        }
	        int mid=start+((end-start)/2);
	        int left=((mid-1+n)%n),right=((mid+1)%n);
	        if((a[mid]<a[left])&&(a[mid]<a[right]))
	        {
	            return mid;
	        }
	        if((a[start]>a[mid]))
	        {
	            end=left;
	        }else{
	            start=right;
	        }
	    }
	    return -1;
	}

};
