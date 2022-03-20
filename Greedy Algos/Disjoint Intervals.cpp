
Problem Description

Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of 
mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.

Example Input
Input 1:

 A = [
       [1, 4]
       [2, 3]
       [4, 6]
       [8, 9]
     ]
Input 2:

 A = [
       [1, 9]
       [2, 3]
       [5, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 Intervals: [ [1, 4], [2, 3], [4, 6], [8, 9] ]
 Intervals [2, 3] and [1, 4] overlap.
 We must include [2, 3] because if [1, 4] is included thenwe cannot include [4, 6].
 We can include at max three disjoint intervals: [[2, 3], [4, 6], [8, 9]]

struct node{
    int start,end;  
};
bool comparator(node a,node b)
{
    return a.end<b.end;
}
int Solution::solve(vector<vector<int> > &arr) {
    int n=arr.size();
    node *a=new node[n];
    for(int i=0;i<n;i++)
    {
        a[i].start=arr[i][0];
        a[i].end=arr[i][1];
    }
    sort(a,a+n,comparator);
    int cnt=1;
    int last_end=a[0].end;
    for(int i=1;i<n;i++)
    {
        if(a[i].start>last_end)
        {
            cnt++;
            last_end=a[i].end;
        }
    }
    return cnt;
}

