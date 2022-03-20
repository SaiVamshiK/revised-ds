
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

Input Format
First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1<=N,M<=1000 GRID(i,j)='X' or 'O'

Output Format
If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If solution doesn't exist, just print "-1".

Sample Input
5 4
OXOO
OOOX
OOXO
XOOO
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
0 0 0 1 

#include<bits/stdc++.h>
using namespace std;

void func(int **a,int i,int j,int n,int m,int **sol,bool &ans)
{
	if((i==(n-1))&&(j==(m-1)))
	{
		ans=true;
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<m;y++)
			{
				cout<<sol[x][y]<<' ';
			}
			cout<<endl;
		}
		return ;
	}
	if((j+1<m)&&(a[i][j+1]==0))
	{
		sol[i][j+1]=1;
		func(a,i,j+1,n,m,sol,ans);
		if(ans)
		{
			return ;
		}
		sol[i][j+1]=0;
	}
	if((i+1<n)&&(a[i+1][j]==0))
	{
		sol[i+1][j]=1;
		func(a,i+1,j,n,m,sol,ans);
		if(ans)
		{
			return ;
		}
		sol[i+1][j]=0;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	char ch;
	int **a=new int*[n];
	int **sol=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		sol[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			sol[i][j]=0;
			cin>>ch;
			if(ch=='X')
			{
				a[i][j]=1;
			}else{
				a[i][j]=0;
			}
		}
	}
	if(a[0][0]==1||(a[n-1][m-1]==1))
	{
		cout<<-1;
		return 0;
	}
	sol[0][0]=1;
	bool ans=false;
	func(a,0,0,n,m,sol,ans);
	if(!ans)
	{
		cout<<-1;
	}
}
