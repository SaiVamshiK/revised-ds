A peak element in an array is the one that is not smaller than its neighbours.
Given an array arr[] of size N, find the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 



int peakElement(int a[], int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return ((a[0]>=a[1])?0:1);
    }
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if((mid==0)&&(a[mid]>=a[mid+1]))
        {
            return 0;
        }
        if((mid==(n-1))&&(a[mid]>=a[mid-1]))
        {
            return mid;
        }
        if((a[mid]>=a[mid+1])&&(a[mid]>=a[mid-1]))
        {
            return mid;
        }
        if(a[mid]<a[mid+1])
        {
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}
