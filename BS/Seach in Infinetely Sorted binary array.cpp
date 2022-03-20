You are given an infinite array consisting of only ones and zeroes, in sorted order. You have to find the index of the first occurrence of 1.
For Example:
If the array is 0 0 0 0 1 1 1 1… then the first occurrence of 1 will be at index 4.
long long firstOne()
{
    if(get(0)==1)
    {
        return 0;
    }
    if(get(1)==1)
    {
        return 1;
    }
    long long start=0,end=1;
    while(get(end)==0)
    {
        start=end;
        end=end*2;
    }
    long long ans=end;
    while(start<=end)
    {
        long long mid=start+((end-start)/2);
        if(get(mid)==1)
        {
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}


