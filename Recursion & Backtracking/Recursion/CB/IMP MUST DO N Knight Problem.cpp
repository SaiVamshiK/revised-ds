
Take as input N, the size of a chess board. We are asked to place N number of Knights in it, so that no knight can kill other.

a. Write a recursive function which returns the count of different distinct ways the knights can be placed across the board. Print the value returned.

b.Write a recursive function which prints all valid configurations (void is the return type for function).

Input Format
Enter the size of the chessboard N

Constraints
None

Output Format
Display the number of ways a knight can be placed and print all the possible arrangements in a space separated manner

Sample Input
2
Sample Output
{0-0} {0-1}  {0-0} {1-0}  {0-0} {1-1}  {0-1} {1-0}  {0-1} {1-1}  {1-0} {1-1} 
6

#include<bits/stdc++.h>
using namespace std;
bool isPossible(int **a,int i,int j,int n)
{
	if((i+2<n)&&(j+1<n)&&(a[i+2][j+1]==1))
	{
		return false;
	}
	if((i+1<n)&&(j+2<n)&&(a[i+1][j+2]==1))
	{
		return false;
	}
	if((i-1>=0)&&(j+2<n)&&(a[i-1][j+2]==1))
	{
		return false;
	}
	if((i-2>=0)&&(j+1<n)&&(a[i-2][j+1]==1))
	{
		return false;
	}
	if((i-2>=0)&&(j-1>=0)&&(a[i-2][j-1]==1))
	{
		return false;
	}
	if((i-1>=0)&&(j-2>=0)&&(a[i-1][j-2]==1))
	{
		return false;
	}
	if((i+1<n)&&(j-2>=0)&&(a[i+1][j-2]==1))
	{
		return false;
	}
	if((i+2<n)&&(j-1>=0)&&(a[i+2][j-1]==1))
	{
		return false;
	}
	return true;
}
void func(int **a,int i,int j,int n,int cnt,int &ans)
{
	if(cnt==n)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				if(a[x][y]==1)
				{
					cout<<"{"<<x<<"-"<<y<<"}"<<" ";
				}
			}
		}
        cout<<' ';
        ans++;
		return ;
	}
	if(i==n)
	{
		return ;
	}
	if(j==n)
	{
		func(a,i+1,0,n,cnt,ans);
		return ;
	}
	if(isPossible(a,i,j,n))
	{
		a[i][j]=1;
		func(a,i,j+1,n,cnt+1,ans);
		a[i][j]=0;
	}
	func(a,i,j+1,n,cnt,ans);
}
int main()
{
	int n;
	cin>>n;
	int **a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	int ans=0;
	func(a,0,0,n,0,ans);
	cout<<endl<<ans;
}

