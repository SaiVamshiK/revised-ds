
Find out the number of N digit numbers, whose digits on being added equals to a given number S. 
Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

const int mod=1e9+7;
typedef long long ll;

ll func(ll cur_sum,ll req_sum,ll cur_digits,ll req_digits,vector<vector<ll>> &dp)
{
    if(cur_sum==req_sum&&(cur_digits==req_digits))
    {
        return 1;
    }
    if(cur_digits==req_digits)
    {
        return INT_MIN;
    }
    if(dp[cur_sum][cur_digits]!=-1)
    {
        return dp[cur_sum][cur_digits];
    }
    ll ans=0;
    for(ll i=0;i<10;i++)
    {
        if(i==0&&(cur_digits==0))
        {
            continue;
        }
        ll cur_elem=i;
        if((cur_elem+cur_sum)<=req_sum)
        {
            ll op1=func(cur_sum+cur_elem,req_sum,cur_digits+1,req_digits,dp);
            if(op1!=INT_MIN)
            {
                ans+=(op1);
                ans%=mod;
            }
        }else{
            break;
        }
    }
    return dp[cur_sum][cur_digits]=ans;
}

int Solution::solve(int A, int B) {
    vector<vector<ll>> dp(B+1,vector<ll>(A+1,-1));
    ll ans=func(0,B,0,A,dp);
    return ans;
}

