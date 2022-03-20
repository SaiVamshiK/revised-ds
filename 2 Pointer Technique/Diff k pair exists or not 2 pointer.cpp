
Given an array ‘A’ of sorted integers and another non negative integer k, 
find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4

int Solution::diffPossible(vector<int> &a, int diff) {
    int n=a.size();
    diff=abs(diff);
    sort(a.begin(),a.end());
    int i=0,j=1;
    while(j<n)
    {
        int cur=a[j]-a[i];
        if(cur<diff)
        {
            j++;
        }else if(cur>diff)
        {
            i++;
        }else{
            return true;
        }
        if(i==j)
        {
            j++;
        }
    }
    return false;
}

