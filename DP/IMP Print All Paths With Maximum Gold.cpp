
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.
8. Also, you have to print all paths with maximum gold.

#include<bits/stdc++.h>
using namespace std;
void printPaths(int **dp,int i,int j,int n,int m,vector<string> &path,vector<vector<string>> &allPaths)
{
	if(j==(m-1))
	{
		allPaths.push_back(path);
		return ;
	}
	int maxVal=INT_MIN;
	// i-1,j+1 => d1
	if((i-1>=0)&&(j+1<m))	
	{
		maxVal=max(maxVal,dp[i-1][j+1]);
	}
	// i,j+1 => d2
	if((j+1<m))
	{
		maxVal=max(maxVal,dp[i][j+1]);
	}
	// i+1,j+1 => d3
	if((i+1<n)&&(j+1<m))
	{
		maxVal=max(maxVal,dp[i+1][j+1]);
	}
	if((i-1>=0)&&(j+1<m)&&(dp[i-1][j+1]==maxVal))
	{
		path.push_back("d1");
		printPaths(dp,i-1,j+1,n,m,path,allPaths);
		path.pop_back();
	}
	if((j+1<m)&&(dp[i][j+1]==maxVal))
	{
		path.push_back("d2");
		printPaths(dp,i,j+1,n,m,path,allPaths);
		path.pop_back();
	}
	if((i+1<n)&&(j+1<m)&&(dp[i+1][j+1]==maxVal))
	{
		path.push_back("d3");
		printPaths(dp,i+1,j+1,n,m,path,allPaths);
		path.pop_back();
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **a=new int*[n];
	int **dp=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		dp[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			dp[i][j]=0;
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		dp[i][m-1]=a[i][m-1];
	}
	for(int j=m-2;j>=0;j--)
	{
		for(int i=0;i<n;i++)
		{
			// i,j 
			// i-1,j+1
			int maxVal=INT_MIN;
			if((i-1>=0)&&(j+1))
			{
				maxVal=max(maxVal,dp[i-1][j+1]);
			}
			// i,j+1
			if((j+1<m))
			{
				maxVal=max(maxVal,dp[i][j+1]);
			}
			// i+1,j+1
			if((i+1<n)&&(j+1<m))
			{
				maxVal=max(maxVal,dp[i+1][j+1]);
			}
			maxVal+=a[i][j];
			dp[i][j]=maxVal;
		}
	}
	int maxGold=INT_MIN;
	for(int i=0;i<n;i++)
	{
		maxGold=max(maxGold,dp[i][0]);
	}
	cout<<maxGold<<endl;
	for(int i=0;i<n;i++)
	{
		if(dp[i][0]==maxGold)
		{
			vector<vector<string>> allPaths;
			vector<string> path;
			path.push_back(to_string(i));
			printPaths(dp,i,0,n,m,path,allPaths);
			for(int j=0;j<(allPaths.size());j++)
			{
				for(int k=0;k<(allPaths[j].size());k++)
				{
					cout<<allPaths[j][k]<<' ';
				}
				cout<<endl;
			}
		}
	}
}



