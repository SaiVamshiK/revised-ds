Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Example 1:

Input:
N = 2
Output: 4
Explanation: The reverse of 2 is 2
and after raising power of 2 by 2 
we get 4 which gives remainder as 
4 by dividing 1000000007.

const int MOD=1e9+7;
class Solution{
    public:
    //You need to complete this fucntion
    long long func(int a,int n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return a;
        }
        if(n%2!=0)
        {
            long long ans=(long long)a*func(a,n-1);
            ans=ans%MOD;
            return ans;
        }else{
            long long ans=(long long)func(a,n/2);
            ans=ans%MOD;
            return ((ans%MOD)*(long long)(ans%MOD))%MOD;
        }
    }
    
    long long power(int a,int n)
    {
        return func(a,n);
    }

};

const int MOD=1e9+7;
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int n,int p)
    {
        long long res=1;
        while(p!=0)
        {
            if(p%2==0)
            {
                n=((n%MOD)*((long long)n%MOD))%MOD;
                p=p/2;
            }else{
                res=((res%MOD)*((long long)n%MOD))%MOD;
                p--;
            }
        }
        return res;
    }

};
