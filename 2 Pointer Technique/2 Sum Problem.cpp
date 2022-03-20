Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

struct node{
    int num;
    int idx;
};
bool comparator(node a,node b)
{
    return a.num<b.num;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        node *a=new node[n];
        for(int i=0;i<n;i++)
        {
            a[i].num=nums[i];
            a[i].idx=i;
        }
        int i=0,j=n-1;
        sort(a,a+n,comparator);
        while(i<=j)
        {
            int cur_sum=a[i].num+a[j].num;
            if(cur_sum==target)
            {
                vector<int> ans;
                ans.push_back(a[i].idx);
                ans.push_back(a[j].idx);
                return ans;
            }else if(cur_sum>target)
            {
                j--;
            }else{
                i++;
            }
        }
        vector<int> ans;
        return ans;
    }
};
