Problem Description

Given an array A of N non-negative numbers and you are also given non-negative number B.

You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.



Problem Constraints
1 <= N <= 104

1 <= A[i] <= 100

1 <= B <= 108



Input Format
First argument is an integer array A.

Second argument is an integer B.



Output Format
Return an integer denoting the number of subarrays in A having sum less than B.



Example Input
Input 1:

 A = [2, 5, 6]
 B = 10
Input 2:

 A = [1, 11, 2, 3, 15]
 B = 10


Example Output
Output 1:

 4
Output 2:

 4

int Solution::solve(vector<int> &a, int sum) {
    int n=a.size();
    int total=((n)*(n+1))/2;
    int cnt=0;
    int i=0,j=0;
    int cur_sum=0;
    while(j<n)
    {
        cur_sum+=a[j];
        if(cur_sum<sum)
        {
            j++;
        }else{
            cnt+=(n-j);
            while(cur_sum>=sum)
            {
                cur_sum-=a[i];
                i++;
                if(cur_sum>=sum)
                {
                    cnt+=(n-j);
                }
            }
            j++;
        }
    }
    return total-cnt;
}
// Total subarrays - number of subarrays with sum>=k

