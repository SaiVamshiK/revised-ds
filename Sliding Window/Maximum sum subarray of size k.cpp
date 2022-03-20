

// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &a , int n){
        int i=0,j=0;
        int window_ans=0;
        int ans=INT_MIN;
        while(j<n)
        {
            if((j-i+1)<k)
            {
                window_ans+=a[j];
                j++;
            }else if((j-i+1)==k)
            {
                window_ans+=a[j];
                ans=max(ans,window_ans);
                j++;
                window_ans-=a[i];
                i++;
            }
        }
        return ans;
    }
};
