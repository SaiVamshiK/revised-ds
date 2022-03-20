
Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

typedef long long ll;
int Solution::sqrt(int n) {
    if(n==0||(n==1))
    {
        return n;
    }
    ll start=1,end=n;
    ll ans=-1;
    while(start<=end)
    {
        ll mid=start+((end-start)/2);
        if(((ll)mid*mid)==n)
        {
            return mid; 
        }else if((mid*mid)<n)
        {
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

