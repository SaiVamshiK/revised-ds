

Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never 
be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given 
instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, 
we need different platforms,

 

Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int a[], int d[], int n)
    {
        sort(a,a+n);
        sort(d,d+n);
        int i=0,j=0;
        int cnt=0;
        int ans=INT_MIN;
        while(i<n)
        {
            if(a[i]<=d[j])
            {
                cnt++;
                ans=max(ans,cnt);
                i++;
            }else{
                cnt--;
                j++;
            }
        }
        return ans;
    }
};
