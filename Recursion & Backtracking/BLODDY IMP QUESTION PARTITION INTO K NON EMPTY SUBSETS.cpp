
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets 
with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.

Example 1:

Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), 
(1, 5), (6)
​Example 2:

Input: 
N = 5 
a[] = {2,1,5,5,6}
K = 3
Output: 
0
Explanation: It is not possible to divide
above array into 3 parts with equal sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isKPartitionPossible() which takes the array a[], the 
size of the array N, and the value of K as inputs and returns true(same as 1) if possible, otherwise false(same as 0).

Expected Time Complexity: O(KN-K*K!).
Expected Auxiliary Space: O(N).

/*You are required to complete this method */

void func(int a[],int n,bool *visited,int k,int cur_sum,int &req_sum,bool &ans)
{
    if(k==1)
    {
        ans=true;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int val=a[i];
            if(cur_sum+val<=req_sum)
            {
                visited[i]=true;
                if(cur_sum+val==req_sum)
                {
                    func(a,n,visited,k-1,0,req_sum,ans);
                }else{
                    func(a,n,visited,k,cur_sum+val,req_sum,ans);
                }
                if(ans)
                {
                    return ;
                }
                visited[i]=false;
            }
        }
    }
}

bool isKPartitionPossible(int a[], int n, int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    if(sum%k!=0)
    {
        return false;
    }
    int req_sum=sum/k;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    bool ans=false;
    func(a,n,visited,k,0,req_sum,ans);
    return ans;
}



