#include<bits/stdc++.h>
using namespace std;
bool isPossible(int **mat,int row,int col,int val,int n)
{
	for(int i=row-1;i>=0;i--)
	{
		if(mat[i][col]==val)
		{
			return false;
		}
	}
	for(int i=row-1,j=col-1;i>=0&&(j>=0);i--,j--)
	{
		if(mat[i][j]==val)
		{
			return false;
		}
	}
	for(int i=row-1,j=col+1;i>=0&&(j<n);i--,j++)
	{
		if(mat[i][j]==val)
		{
			return false;
		}
	}
	return true;
}
void func(int **mat,int row,int n,int &ans)
{
	if(row==n)
	{
		ans++;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(isPossible(mat,row,i,1,n))
		{
			mat[row][i]=1;
			func(mat,row+1,n,ans);
			mat[row][i]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int **mat=new int*[n];
	for(int i=0;i<n;i++)
	{
		mat[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			mat[i][j]=0;
		}
	}
	int ans=0;
	func(mat,0,n,ans);
	cout<<ans;
}
