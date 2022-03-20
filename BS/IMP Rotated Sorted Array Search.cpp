
int Solution::search(const vector<int> &a, int x) {
    int n=a.size();
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(a[mid]==x)
        {
            return mid;
        }
        if(a[start]<=a[mid])
        {
            if(a[start]<=x&&(x<=a[mid]))
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(a[mid]<=x&&(x<=a[end]))
            {
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}


There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

class Solution {
public:
    int search(vector<int>& a, int x) {
        int n=a.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(a[mid]==x)
            {
                return mid;
            }
            else if(a[start]<=a[mid])
            {
                if(a[start]<=x&&(x<=a[mid]))
                {
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                if(a[mid]<=x&&(x<=a[end]))
                {
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array 
is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

class Solution {
public:
    bool func(vector<int> &a,int start,int end,int key)
    {
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(a[mid]==key)
            {
                return true;
            }else if(a[mid]>key)
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
    int search(vector<int>& a, int x) {
        int idx=-1;
        int n=a.size();
        if(n==0)
        {
            return -1;
        }
        if(n==1)
        {
            if(a[0]==x)
            {
                return 0;
            }
            return -1;
        }
        int start=0,end=n-1;
        while(start<=end)
        {
            if(a[start]<a[end])
            {
                idx=start;
                break;
            }
            int mid=start+((end-start)/2);
            int left=((mid-1+n)%n),right=((mid+1)%n);
            if(a[mid]<a[left]&&(a[mid]<a[right]))
            {
                idx=mid;
                break;
            }
            if((a[start]>a[mid]))
            {
                end=left;
            }else{
                start=right;
            }
        }
        if(idx==0)
        {
            if(!func(a,0,n-1,x))
            {
                return -1;
            }
            return lower_bound(a.begin(),a.end(),x)-a.begin();
        }
        // 0 to idx-1,idx to n-1
        if((a[0]<=x)&&(x<=a[idx-1]))
        {
            cout<<"hi";
            if(!func(a,0,idx-1,x))
            {
                return -1;
            }
            return lower_bound(a.begin(),a.begin()+idx-1,x)-a.begin();
        }
        if((a[idx]<=x)&&(x<=a[n-1]))
        {
            if(!func(a,idx,n-1,x))
            {
                return -1;
            }
            return lower_bound(a.begin()+idx,a.end(),x)-a.begin();
        }
        return -1;
    }
};













