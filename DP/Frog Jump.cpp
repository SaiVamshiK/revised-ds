
1. You are given an array of positive integers in ascending order, which represents the position of stones in the river.
2. A frog is trying to cross a river. It can jump on a stone, but it must not jump into the water.
3. You have to find if the frog can cross the river by landing on the last stone.
4. The frog is on the first stone initially, and from first stone it can jump 1 unit only.
5. The frog can only jump k-1, k, or k+1 units in the forward direction, where k is the frog's last jump.
Input Format
A number N 
a1
a2.. N numbers
Output Format
true/false

https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/frog-jump-official/ojquestion#!

#include<bits/stdc++.h>
using namespace std;
bool func(int *a,int idx,int n,int prevJump,vector<vector<int>> &dp)
{
    if(idx==(n-1))
    {
        return true;
    }
    if(dp[idx][prevJump]!=-1)
    {
        return dp[idx][prevJump];
    }
    int posJump1=prevJump-1;
    int posJump2=prevJump;
    int posJump3=prevJump+1;
    vector<int> posJumps;
    if(posJump1!=0)
    {
        posJumps.push_back(posJump1);
    }
    if(posJump2!=0)
    {
        posJumps.push_back(posJump2);
    }
    if(posJump3!=0)
    {
        posJumps.push_back(posJump3);
    }
    for(int i=0;i<(posJumps.size());i++)
    {
        int curJump=posJumps[i];
        int nextPos=a[idx]+curJump;
        for(int j=idx+1;j<n;j++)
        {
            if(a[j]==nextPos)
            {
                bool ans=func(a,j,n,curJump,dp);
                if(ans)
                {
                    return dp[idx][prevJump]=true;
                }
                break;
            }
        }
    }
    return dp[idx][prevJump]=false;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    int maxVal;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxVal=a[n-1];
    if((a[1]-a[0])!=1)
    {
        cout<<"false"<<endl;
    }else{
        vector<vector<int>> dp(n+1,vector<int>(maxVal+1,-1));
        bool ans=func(a,1,n,1,dp);
        if(ans)
        {
            cout<<"true"<<endl;   
        }else{
            cout<<"false"<<endl;   
        }
    }
}
















