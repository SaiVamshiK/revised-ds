
Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


Problem Constraints
3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.



Input Format
First argument is an integer array A denoting the bitonic sequence.

Second argument is an integer B.



Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.



Example Input
Input 1:

 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20
Input 2:

 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30


Example Output
Output 1:

 3

int find(vector<int> &a,int start,int end,int key,bool ascending)
{
    if(ascending)
    {
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(a[mid]==key)
            {
                return mid;
            }else if(a[mid]>key)
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }else{
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(a[mid]==key)
            {
                return mid;
            }else if(a[mid]>key)
            {
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
}
int Solution::solve(vector<int> &a, int key) {
    int n=a.size();
    int start=0,end=n-1;
    int idx=-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        int left=mid-1,right=mid+1;
        if((left>=0)&&(a[mid]>a[left])&&(right>=0)&&(a[mid]>a[right]))
        {
            idx=mid;
            break;
        }
        if((left>=0)&&(a[mid]<a[left]))
        {
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    if(key==a[idx])
    {
        return idx;
    }
    int left1=find(a,0,idx-1,key,true),right1=find(a,idx+1,n-1,key,false);
    if(left1==-1&&(right1==-1))
    {
        return -1;
    }
    if(left1!=-1)
    {
        return left1;
    }
    return right1;
}

