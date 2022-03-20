Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.

int Solution::solve(vector<vector<int> > &a) {
    int n=a.size();
    int *start=new int[n];
    int *end=new int[n];
    for(int i=0;i<n;i++)
    {
        start[i]=a[i][0];
        end[i]=a[i][1];
    }
    sort(start,start+n);
    sort(end,end+n);
    int i=0,j=0;
    int ans=0,cnt=0;
    while(i<n)
    {
        if(start[i]<end[j])
        {
            cnt++;
            ans=max(ans,cnt);
            i++;
        }else if(start[i]>=end[j])
        {
            cnt--;
            j++;
        }
    }
    return ans;
}

