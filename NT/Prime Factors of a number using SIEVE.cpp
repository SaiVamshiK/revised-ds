
Given a number N. Find its unique prime factors in increasing order.
 

Example 1:

Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime
factors of 100.

class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    vector<int> lpf(n+1,-1);
	    for(int i=0;i<=n;i++)
	    {
	        lpf[i]=i;
	    }
	    for(int i=2;(i*i)<=n;i++)
	    {
	        if(lpf[i]==i)
	        {
	            int elem=i,mul=i;
	            while((elem*mul)<=n)
	            {
	                if(lpf[(elem*mul)]==(elem*mul))
	                {
	                    lpf[(elem*mul)]=i;
	                }
	                mul++;
	            }
	        }
	    }
	    vector<int> ans;
	    while(n!=1)
	    {
	        int lowest_prime_factor=lpf[n];
	        while((n%lowest_prime_factor)==0)
	        {
	            n=n/lowest_prime_factor;
	        }
	        ans.push_back(lowest_prime_factor);
	    }
	    return ans;
	}
};


