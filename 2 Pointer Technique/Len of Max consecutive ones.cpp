
Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s 
possible by changing at most B ‘0’s.



Problem Constraints
1 <= N, B <= 105

A[i]=0 or A[i]=1



Input Format
First argument is an binary array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Example Input
Input 1:

 A = [1, 0, 0, 1, 1, 0, 1]
 B = 1
 
************************** SEE THIS SOLUTION *************************
 
class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            if(a[j]==0)
            {
                k--;
            }
            if(k>0)
            {
                ans=max(ans,j-i+1);
                j++;
            }else if(k==0)
            {
                ans=max(ans,j-i+1);
                j++;
            }else{
                while(k<0)
                {
                    if(a[i]==0)
                    {
                        k++;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

int Solution::solve(vector<int> &a, int k) {
    int n=a.size();
    int i=0,j=0;
    int max_len=INT_MIN;
    while(j<n)
    {
        if(a[j]==0)
        {
            k--;
        }
        if(k>0)
        {
            int cur_len=j-i+1;
            if(max_len<cur_len)
            {
                max_len=cur_len;
            }
            j++;
        }else if(k==0)
        {
            j++;
            while(j<n&&(a[j]==1))
            {
                j++;
            }
            j--;
            int cur_len=j-i+1;
            if(max_len<cur_len)
            {
                max_len=cur_len;
            }
            j++;
        }else{
            while(k<0)
            {
                if(a[i]==0)
                {
                    k++;
                }
                i++;
            }
            j++;
        }
    }
    return max_len;
}

