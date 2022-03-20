1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
7. You are required to traverse through the matrix and print the cost of the path which is least costly.
8. Also, you have to print all the paths with minimum cost.

#include<bits/stdc++.h>
using namespace std;
void func(int **dp,int i,int j,int n,int m,string &op,vector<string> &ans)
{
	if((i==(n-1))&&(j==(m-1)))
	{
		ans.push_back(op);
		return ;
	}
	// i+1,j => V
	// i,j+1 => H
	int val1=INT_MAX,val2=INT_MAX;
	if((i+1<n))
	{
		val1=dp[i+1][j];
	}
	if((j+1<m))
	{
		val2=dp[i][j+1];
	}
	if(val1<val2)
	{
		op.push_back('V');
		func(dp,i+1,j,n,m,op,ans);
		op.pop_back();
	}else if(val1>val2)
	{
		op.push_back('H');
		func(dp,i,j+1,n,m,op,ans);
		op.pop_back();
	}else{
		op.push_back('V');
		func(dp,i+1,j,n,m,op,ans);
		op.pop_back();
		op.push_back('H');
		func(dp,i,j+1,n,m,op,ans);
		op.pop_back();
	}
}
void printPaths(int **dp,int n,int m)
{
	string op="";
	vector<string> ans;
	func(dp,0,0,n,m,op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		cout<<ans[i]<<endl;
	}
}
int main()
{
    int n,m,x;
    cin>>n>>m;
    int **a=new int*[n];
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[n-1][m-1]=a[n-1][m-1];
    for(int i=n-2;i>=0;i--)
    {
    	dp[i][m-1]=a[i][m-1]+dp[i+1][m-1];
	}
	for(int i=m-2;i>=0;i--)
	{
		dp[n-1][i]=a[n-1][i]+dp[n-1][i+1];
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i][j+1]);
		}
	}
	cout<<dp[0][0]<<endl;
	printPaths(dp,n,m);
}







