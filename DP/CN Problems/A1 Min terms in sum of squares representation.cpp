
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

***************************************		SEE THIS APPROACH		***************************************

int minCount(int n)
{
	int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=i;
    }
    for(int i=3;i<=n;i++)
    {
        int cur=i;
        int cur_ans=INT_MAX;
        for(int j=1;(j*j)<=cur;j++)
        {
            cur_ans=min(cur_ans,1+dp[cur-(j*j)]);
        }
        dp[cur]=cur_ans;
    }
    return dp[n];
}



int minCount(int n)
{
	int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        int square_root=floor(sqrt(i));
        dp[i]=i;
        for(int j=1;j<=square_root;j++)
        {
            dp[i]=min(dp[i],1+dp[i-(j*j)]);
        }
    }
    return dp[n];
}
















