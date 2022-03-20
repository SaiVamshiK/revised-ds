
Given an array ‘A’ of sorted integers and another non negative integer k, 
find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4

int Solution::diffPossible(vector<int> &a, int diff) {
    int n=a.size();
    int i=0,j=0;
    while(j<n)
    {
        if(i==j)
        {
            j++;
        }
        int cur_diff=a[j]-a[i];
        if(cur_diff==diff)
        {
            return true;
        }else if(cur_diff<diff)
        {
            j++;
        }else{
            i++;
        }
    }
    return false;
}

