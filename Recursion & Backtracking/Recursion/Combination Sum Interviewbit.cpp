Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 = a2 = … = ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]

*******************************************
HERE TO MAINTAIN THE SORTED ORDER OF COMBINATIONS ONE EASY THING THAT WE COULD PROBALY DO IS SORT THE GIVEN ARRAY ITSELF
IMP CONCEPT THIS IS
*******************************************


void func(vector<int> &inp,int i,int n,int sum,vector<int> &op,set<vector<int>> &st)
{
    if(sum==0)
    {
        st.insert(op);
        return ;
    }
    if(i==n)
    {
        return ;
    }
    int cur=inp[i];
    if(cur<=sum)
    {
        op.push_back(cur);
        func(inp,i,n,sum-cur,op,st);
        op.pop_back();
        func(inp,i+1,n,sum,op,st);
    }else{
        func(inp,i+1,n,sum,op,st);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &a, int target) {
    sort(a.begin(),a.end());
    set<vector<int>> st;
    int n=a.size();
    vector<int> op;
    func(a,0,n,target,op,st);
    vector<vector<int> > ans;
    for(auto it=st.begin();it!=st.end();it++)
    {
        ans.push_back((*it));
    }
    return ans;
}

