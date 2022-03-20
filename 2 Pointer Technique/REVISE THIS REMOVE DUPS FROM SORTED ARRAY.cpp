
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example:
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]

********************
See this
********************

int Solution::removeDuplicates(vector<int> &a) {
    int n=a.size();
    if(n==1)
    {
        return 1;
    }
    int i=0,j=0;
    while(j<n)
    {
        while(j<n&&(a[j]==a[i]))
        {
            j++;
        }
        if(j==n)
        {
            return i+1;
        }
        i++;
        swap(a[i],a[j]);
        j++;
    }
    return i+1;
}


int Solution::removeDuplicates(vector<int> &a) {
    int n=a.size();
    if(n==0||(n==1))
    {
        return n;
    }
    int i=0,j=1;
    while(j<n)
    {
        int cur=a[i];
        while(j<n&&(a[j]==cur))
        {
            j++;
        }
        if(j>=n)
        {
            return i+1;
            break;
        }
        i++;
        swap(a[i],a[j]);
        j++;
    }
    return i+1;
}

int Solution::removeDuplicates(vector<int> &a) {
    int n=a.size();
    if(n==0||(n==1))
    {
        return n;
    }
    int i=0,j=1;
    while(j<n)
    {
        int cur=a[i];
        while(j<n&&(a[j]==cur))
        {
            j++;
        }
        if(j<n)
        {
            i++;
            swap(a[i],a[j]);
            j++;    
        }else{
            return i+1;   
        }
    }
    return i+1;
}

