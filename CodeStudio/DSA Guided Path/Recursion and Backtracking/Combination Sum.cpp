
Problem Statement
You are given an array/list ARR of N distinct positive integers. You are also given a non-negative integer B.
Your task is to find all unique combinations in the array whose sum is equal to B. A number can be chosen any number of times from array/list ARR.
Elements in each combination must be in non-decreasing order.
For example:
Let the array ARR be [1, 2, 3] and B = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)

#include<bits/stdc++.h>
using namespace std;
void func(vector<int> &a,int i,int n,int curSum,int sum,
         	vector<int> &op,vector<vector<int>> &ans)
{
    if(sum==curSum)
    {
        ans.push_back(op);
        return ;
    }
    if(i==n)
    {
        return ;
    }
    if((a[i]+curSum)<=sum)
    {
        op.push_back(a[i]);
        func(a,i,n,curSum+a[i],sum,op,ans);
        op.pop_back();
        func(a,i+1,n,curSum,sum,op,ans);
    }else{
        return ;
    }
}
vector<vector<int>> combSum(vector<int>& a, int sum)
{
	int n=a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    vector<int> op;
    func(a,0,n,0,sum,op,ans);
    return ans;
}

