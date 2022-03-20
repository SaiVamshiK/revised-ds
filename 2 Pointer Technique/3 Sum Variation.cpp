
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

int Solution::threeSumClosest(vector<int> &a, int sum) {
    int n=a.size();
    sort(a.begin(),a.end());
    int ans,diff=INT_MAX;
    int start=0;
    while(start<n)
    {
        int cur=a[start];
        int i=start+1,j=n-1;
        while(i<j)
        {
            int req=sum-cur;
            int cur_sum=a[i]+a[j];
            if(cur_sum==req)
            {
                return (a[i]+a[j]+cur);
            }else if(cur_sum<req)
            {
                if(diff>abs(req-cur_sum))
                {
                    diff=abs(req-cur_sum);
                    ans=a[i]+a[j]+cur;
                }
                i++;
            }else{
                if(diff>abs(req-cur_sum))
                {
                    diff=abs(req-cur_sum);
                    ans=a[i]+a[j]+cur;
                }
                j--;
            }
        }
        start++;
    }
    return ans;
}

