
Given a number N, find least prime factors for all numbers from 1 to N.  
The least prime factor of an integer N is the smallest prime number that divides it.
Note : The least prime factor of all even numbers is 2. 
A prime number is its own least prime factor (as well as its own greatest prime factor).1 needs to be printed for 1

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            ans[i]=i;
        }
        for(int i=2;(i*i<=n);i++)
        {
            if(ans[i]==i)
            {
                int elem=i;
                int mul=i;
                while((elem*mul)<=n)
                {
                    if(ans[(elem*mul)]==(elem*mul))
                    {
                        ans[(elem*mul)]=i;
                    }
                    mul++;
                }
            }
        }
        return ans;
    }
};
