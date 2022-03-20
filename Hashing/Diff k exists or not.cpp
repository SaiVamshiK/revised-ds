
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j 
such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

int Solution::diffPossible(const vector<int> &a, int diff) {
    unordered_map<int,int> mp;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        int cur=a[i];
        mp[cur]++;
    }
    for(int i=0;i<n;i++)
    {
        mp[a[i]]--;
        if(mp.find(a[i]-diff)!=mp.end()&&(mp[a[i]-diff]>0))
        {
            return 1;
        }
        mp[a[i]]++;
    }
    return 0;
}

