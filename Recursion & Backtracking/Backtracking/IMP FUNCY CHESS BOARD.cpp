
A knight is a piece used in the game of chess. The chessboard itself is square array of cells. 
Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. 
Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), 
or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. 
The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left 
square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, 
it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single 
spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1
Sample Output
1

#include<bits/stdc++.h>
using namespace std;
int ans=INT_MIN;
void func(int **a,int i,int j,int n,bool **visited,int cnt)
{
	ans=max(ans,cnt);
	if((i+2<n)&&(j+1<n)&&(!visited[i+2][j+1])&&(a[i+2][j+1]==1))
	{
		visited[i+2][j+1]=true;
		func(a,i+2,j+1,n,visited,cnt+1);
		visited[i+2][j+1]=false;
	}
	if((i+1<n)&&(j+2<n)&&(!visited[i+1][j+2])&&(a[i+1][j+2]==1))
	{
		visited[i+1][j+2]=true;
		func(a,i+1,j+2,n,visited,cnt+1);
		visited[i+1][j+2]=false;
	}
	if((i-1>=0)&&(j+2<n)&&(!visited[i-1][j+2])&&(a[i-1][j+2]==1))
	{
		visited[i-1][j+2]=true;
		func(a,i-1,j+2,n,visited,cnt+1);
		visited[i-1][j+2]=false;
	}
	if((i-2>=0)&&(j+1<n)&&(!visited[i-2][j+1])&&(a[i-2][j+1]==1))
	{
		visited[i-2][j+1]=true;
		func(a,i-2,j+1,n,visited,cnt+1);
		visited[i-2][j+1]=false;
	}
	if((i-2>=0)&&(j-1>=0)&&(!visited[i-2][j-1])&&(a[i-2][j-1]==1))
	{
		visited[i-2][j-1]=true;
		func(a,i-2,j-1,n,visited,cnt+1);
		visited[i-2][j-1]=false;
	}
	if((i-1>=0)&&(j-2>=0)&&(!visited[i-1][j-2])&&(a[i-1][j-2]==1))
	{
		visited[i-1][j-2]=true;
		func(a,i-1,j-2,n,visited,cnt+1);
		visited[i-1][j-2]=false;
	}
	if((i+1<n)&&(j-2>=0)&&(!visited[i+1][j-2])&&(a[i+1][j-2]==1))
	{
		visited[i+1][j-2]=true;
		func(a,i+1,j-2,n,visited,cnt+1);
		visited[i+1][j-2]=false;
	}
	if((i+2<n)&&(j-1>=0)&&(!visited[i+2][j-1])&&(a[i+2][j-1]==1))
	{
		visited[i+2][j-1]=true;
		func(a,i+2,j-1,n,visited,cnt+1);
		visited[i+2][j-1]=false;
	}
}
int main()
{
	int n;
	cin>>n;
	int total_ones=0;
	int **a=new int*[n];
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		visited[i]=new bool[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				total_ones++;
			}
			visited[i][j]=false;
		}
	}
	visited[0][0]=true;
	func(a,0,0,n,visited,1);
	cout<<(total_ones-ans)<<endl;
}
