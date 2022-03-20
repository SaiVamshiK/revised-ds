class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    vector<int> ans;
	    for(int i=2;(i*i)<=n;i++)
	    {
	        if((n%i)==0)
	        {
	            while((n%i)==0)
	            {
	                n=n/i;
	            }
	            ans.push_back(i);
	        }
	    }
	    if(n!=1)
	    {
	        ans.push_back(n);
	    }
	    return ans;
	}
};
