
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a = b = c = d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)

void func(vector<int> &a,int n,int start,int ignore,int reqOverall,vector<vector<int> > &ans,int val)
{
    while(start<n)
    {
        if(ignore==start)
        {
            start++;
        }
        int cur=a[start];
        int i=start+1,j=n-1;
        int req=reqOverall-cur;
        while(i<j)
        {
            if(i==ignore)
            {
                i++;
                continue;
            }
            if(j==ignore)
            {
                j--;
                continue;
            }
            int cur_sum=a[i]+a[j];
            if(cur_sum==req)
            {
                vector<int> temp;
                temp.push_back(val);
                temp.push_back(cur);
                temp.push_back(a[i]);
                temp.push_back(a[j]);
                ans.push_back(temp);
                int x=a[i];
                while(i<n&&(a[i]==x))
                {
                    i++;
                }
                int y=a[j];
                while(j>=0&&(a[j]==y))
                {
                    j--;
                }
            }else if(cur_sum<req)
            {
                i++;
            }else{
                j--;
            }
        }
        int x=a[start];
        while(start<n&&(a[start]==x))
        {
            start++;
        }
    }
}
vector<vector<int> > Solution::fourSum(vector<int> &a, int sum) {
    int n=a.size();
    vector<vector<int> > ans;
    sort(a.begin(),a.end());
    int i=0;
    while(i<n)
    {
        int cur=a[i];
        int req=sum-cur;
        func(a,n,i+1,i,req,ans,cur);
        int x=a[i];
        while(i<n&&(x==a[i]))
        {
            i++;
        }
    }
    return ans;
}

