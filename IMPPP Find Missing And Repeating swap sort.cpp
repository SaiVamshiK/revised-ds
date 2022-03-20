
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing 
and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

int *findTwoElement(int *a, int n) {
        int i=0;
        while(i<n)
        {
            if(a[i]==(i+1))
            {
                i++;
            }else{
                int val=a[i];
                int pos=a[i]-1;
                if(a[i]!=a[pos])
                {
                    swap(a[i],a[pos]);
                }else{
                    i++;
                }
            }
        }
        int *ans=new int[2];
        for(int i=0;i<n;i++)
        {
            if(a[i]!=(i+1))
            {
                ans[0]=a[i];
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
