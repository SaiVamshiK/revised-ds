Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. 
All the students sit in a line, and each of them has a score according to performance. 
Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that 
If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. 
Noor wants to save money, so she wants to minimize the total number of chocolates.


int getMin(int *a, int n)
{
	int *dp=new int[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            int val=dp[i+1]+1;
            dp[i]=max(dp[i],val);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=dp[i];
    }
    return sum;
}


int getMin(int *a, int n)
{
	int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>(a[i-1]))
        {
            dp[i]=max(dp[i],1+dp[i-1]);
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>(a[i+1]))
        {
            dp[i]=max(dp[i],1+dp[i+1]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=dp[i];
    }
    return ans;
}
