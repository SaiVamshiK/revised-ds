
A conveyor belt has packages that must be shipped from one port to another within D days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
 
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

class Solution {
public:
    bool isValid(int wt,vector<int> &a,int n,int D)
    {
        int cnt=1;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cur=cur+a[i];
            if(cur>wt)
            {
                cnt++;
                cur=0;
                if((cur+a[i])<=wt)
                {
                    cur=cur+a[i];
                }else{
                    return false;
                }
            }
            if(cnt>D)
            {
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& a, int D) {
        int n=a.size();
        int start=INT_MIN,end=0;
        for(int i=0;i<n;i++)
        {
            end=end+a[i];
            start=max(start,a[i]);
        }
        int ans=start;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isValid(mid,a,n,D))
            {
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
