Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

 

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int a[], int n, int k){
    int i=0,j=0;
    int sum=0;
    vector<int> ans;
    while(j<n)
    {
        sum+=a[j];
        if(sum<k)
        {
            j++;
        }else if(sum==k)
        {
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }else {
            while(sum>k)
            {
                sum-=a[i];
                i++;
            }
            if(sum==k)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            j++;
        }
    }
    ans.push_back(-1);
    return ans;
}







