
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int a[], int n){ 
        int *left_max=new int[n];
        int *right_max=new int[n];
        left_max[0]=a[0];
        for(int i=1;i<n;i++)
        {
            left_max[i]=max(a[i],left_max[i-1]);
        }
        right_max[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right_max[i]=max(a[i],right_max[i+1]);
        }
        int ans=0;
        for(int i=1;i<(n-1);i++)
        {
            int x=min(left_max[i],right_max[i]);
            if(x>a[i])
            {
                ans+=(x-a[i]);
            }
        }
        return ans;
    }
};
