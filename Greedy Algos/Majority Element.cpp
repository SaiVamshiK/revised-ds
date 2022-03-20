
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

int Solution::majorityElement(const vector<int> &A) {
    vector<int> a;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        a.push_back(A[i]);
    }
    sort(a.begin(),a.end());
    int occs=floor(n/2);
    for(int i=0;i<n;i++)
    {
        int cur=upper_bound(a.begin(),a.end(),a[i])-lower_bound(a.begin(),a.end(),a[i]);
        if(cur>occs)
        {
            return a[i];
        }
    }
    return -1;
}

