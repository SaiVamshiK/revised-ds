
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int sum) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n)
            {
                int cur=a[i]+a[j];
                int req=sum-cur;
                int start=j+1,end=n-1;
                while(start<end)
                {
                    int x=a[start]+a[end];
                    if(x<req)
                    {
                        start++;
                    }else if(x>req)
                    {
                        end--;
                    }else{
                        vector<int> temp;
                        temp.push_back(a[i]);
                        temp.push_back(a[j]);
                        temp.push_back(a[start]);
                        temp.push_back(a[end]);
                        sort(temp.begin(),temp.end());
                        ans.push_back(temp);
                        int checkstart=a[start];
                        while(start<n&&(checkstart==a[start]))
                        {
                            start++;
                        }
                        int checkend=a[end];
                        while(end>=0&&(checkend==a[end]))
                        {
                            end--;
                        }
                    }
                }
                int checkj=a[j];
                while(j<n&&(a[j]==checkj))
                {
                    j++;
                }
            }
            int checki=a[i];
            while(i<n&&(a[i]==checki))
            {
                i++;
            }
        }
        return ans;
    }
};




