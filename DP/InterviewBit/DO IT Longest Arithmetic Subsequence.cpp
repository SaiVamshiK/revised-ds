
Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.



Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer, representing the length of the longest possible arithmetic progression.
Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [3, 6, 9, 12]

Output 1:
    4

Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]

Output 2:
    3

Explanation 2:
    [4, 7, 10] form an arithmetic progression.


int Solution::solve(const vector<int> &a) {
    int n=a.size();
    if(n==1)
    {
        return 1;
    }
    vector<unordered_map<int,int>> dp;
    unordered_map<int,int> ini;
    dp.push_back(ini);
    for(int i=1;i<n;i++)
    {
        unordered_map<int,int> temp;
        for(int j=0;j<i;j++)
        {
            int diff=a[i]-a[j];
            if(dp[j].find(diff)!=dp[j].end())
            {
                if(temp.find(diff)!=temp.end())
                {
                    temp[diff]=max(temp[diff],1+dp[j][diff]);
                }else{
                    temp[diff]=1+dp[j][diff];
                }   
            }else{
                if(temp.find(diff)!=temp.end())
                {
                    temp[diff]=max(temp[diff],1);    
                }else{
                    temp[diff]=1;   
                }
            }
        }
        dp.push_back(temp);
    }
    int ans=INT_MIN;
    for(int i=1;i<n;i++)
    {
        unordered_map<int,int> temp=dp[i];
        for(auto it=temp.begin();it!=temp.end();it++)
        {
            ans=max(ans,it->second+1);
        }
    }
    return ans;
}

