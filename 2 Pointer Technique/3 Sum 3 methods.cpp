
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

************************** BRUTE SOLUTION **************************
O(n^3 * log(m)), m = number of triplets summing to 0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        // a+b+c=0;
        int n=a.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(a[i]+a[j]+a[k]==0)
                    {
                        vector<int> temp;
                        temp.push_back(a[i]);
                        temp.push_back(a[j]);
                        temp.push_back(a[k]);
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back((*it));
        }
        return ans;
    }
};


************************** OPTIMIZED SOLUTION USING HASHTABLE **************************

O(n^2 *log(m)), m = number of triplets with 0 sum;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        // a+b+c=0;
        vector<vector<int>> ans;
        int n=a.size();
        unordered_map<int,int> hash_table;
        for(int i=0;i<n;i++)
        {
            hash_table[a[i]]++;
        }
        set<vector<int >> st;
        for(int i=0;i<n;i++)
        {
            hash_table[a[i]]--;
            for(int j=i+1;j<n;j++)
            {
                hash_table[a[j]]--;
                int req=-(a[i]+a[j]);
                if(hash_table.find(req)!=hash_table.end()&&(hash_table[req]>0))
                {
                    vector<int> temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    temp.push_back(req);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash_table[a[j]]++;
            }
            hash_table[a[i]]++;
        }
        for(auto it=st.begin();it!=st.end();it++)
        {
            ans.push_back((*it));
        }
        return ans;
    }
};

************************** BEST SOLUTION USING 2 POINTER **************************

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int n=a.size();
        int start=0;
        while(start<n)
        {
            int cur=a[start];
            int i=start+1,j=n-1;
            int req_sum=-cur;
            while(i<j)
            {
                int cur_sum=a[i]+a[j];
                if(cur_sum==req_sum)
                {
                    vector<int> temp;
                    temp.push_back(cur);
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                    int x=a[i],y=a[j];
                    while((i<n)&&a[i]==x)
                    {
                        i++;
                    }
                    while((j>=0)&&a[j]==y)
                    {
                        j--;
                    }
                }else if(cur_sum<req_sum)
                {
                    i++;
                }else{
                    j--;
                }
            }
            while(start<n&&(a[start]==cur))
            {
                start++;
            }
        }
        return ans;
    }
};
