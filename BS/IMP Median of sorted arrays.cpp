
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()<b.size())
        {
            swap(a,b);
        }
        if(a.empty()&&(b.empty()))
        {
            return double(0);
        }
        int n=a.size(),m=b.size();
        if(a.empty())
        {
            if(m%2==0)
            {
                double ans1=b[(m/2)];
                double ans2=b[(m/2)-1];
                return double((ans1+ans2)/2);
            }else{
                return double(b[m/2]);
            }
        }
        if(b.empty())
        {
            if(n%2==0)
            {
                double ans1=a[(n/2)];
                double ans2=a[(n/2)-1];
                return double((ans1+ans2)/2);
            }else{
                return double(a[(n/2)]);
            }
        }
        bool isEven=true;
        if((n+m)%2!=0)
        {
            isEven=false;
        }
        int start=-1,end=n-1;
        while(start<=end)
        {
            int i=start+((end-start)/2);
            int j=((n+m)/2)-i-2;
            if(j<-1)
            {
                end=i-1;
                continue;
            }
            if(j>=m)
            {
                start=i+1;
                continue;
            }
            int a1=((i>=0)?a[i]:INT_MIN);
            int a2=((i+1<n)?a[i+1]:INT_MAX);
            int b1=((j>=0)?b[j]:INT_MIN);
            int b2=((j+1<m)?b[j+1]:INT_MAX);
            if((a1<=b2)&&(b1<=a2))
            {
                if(isEven)
                {
                    double ans1=max(a1,b1),ans2=min(a2,b2);
                    return double((ans1+ans2)/2);
                }else{
                    return double(min(a2,b2));
                }
            }
            if(a1>b2)
            {
                end=i-1;
            }else{
                start=i+1;
            }
        }
        return -1;
    }
};
















