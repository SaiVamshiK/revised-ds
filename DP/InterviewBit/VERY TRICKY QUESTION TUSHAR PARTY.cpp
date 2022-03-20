
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
    2 4 6
    2 1 3
    2 5 3

Output:
    14

Explanation: 
    First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14

int func(const vector<int> &a,vector<int> &val,int n,int sum,vector<vector<int>> &dp)
{
    if(sum==0)
    {
        return 0;
    }
    if(n==0)
    {
        return INT_MIN;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        int op1=func(a,val,n,sum-a[n-1],dp);
        int op2=func(a,val,n-1,sum,dp);
        if(op1!=INT_MIN&&(op2!=INT_MIN))
        {
            return dp[n][sum]=max(val[n-1]+op1,op2);    
        }
        if(op1!=INT_MIN)
        {
            return dp[n][sum]=val[n-1]+op1;   
        }
        if(op2!=INT_MIN)
        {
            return dp[n][sum]=op2;
        }
        return dp[n][sum]=INT_MIN;
    }else{
        int op1=func(a,val,n-1,sum,dp);
        if(op1!=INT_MIN)
        {
            return dp[n][sum]=op1;    
        }
        return dp[n][sum]=INT_MIN;
    }
}
int Solution::solve(const vector<int> &cap_friends, const vector<int> &cap_dish, const vector<int> &cost_dish) {
    int ans=0;
    vector<int> cost_of_dish;
    for(int i=0;i<(cost_dish.size());i++)
    {
        cost_of_dish.push_back(-cost_dish[i]);
    }
    int n=cap_dish.size();
    int ini=INT_MIN;
    for(int i=0;i<(cap_friends.size());i++)
    {
        ini=max(ini,cap_friends[i]);
    }
    vector<vector<int>> dp(n+1,vector<int>(ini+1,-1));
    for(int i=0;i<(cap_friends.size());i++)
    {
        int cur=cap_friends[i];
        ans=ans-(func(cap_dish,cost_of_dish,n,cur,dp));
    }
    return ans;
}

