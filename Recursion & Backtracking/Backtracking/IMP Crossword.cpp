
You are given a dictionary consisting of N words each containing lowercase letters 'a'-'z'. You also have MxM crossword consisting of lowercase letters 'a'-'z'. You want to print all possible words that can be formed by a sequence of adjacent characters. Note that you can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell. Note :- if a word is present in crossword more than once print it once.

Input Format
First line contains integer N. Then follow N space seperated words. Next line contains integer M. Then you have M characters each in next M lines forming MxM grid.

Constraints
1 <= N <= 10 1 <= M <= 5

Output Format
Print all words of dictionary present in crossword with space between words.

Sample Input
2
a aa
2
aa
aa
Sample Output
a aa

#include<bits/stdc++.h>
using namespace std;

void func(vector<string> &grid,int i,int j,int n,int m,bool **visited,string &str,int idx,int size,bool &ans)
{
	visited[i][j]=true;
	if(idx==size-1)
	{
		ans=true;
		return ;
	}
	char ch=str[idx+1];
	if((j+1<m)&&(!visited[i][j+1])&&(grid[i][j+1]==ch))
	{
		func(grid,i,j+1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i+1<n)&&(j+1<m)&&(!visited[i+1][j+1])&&(grid[i+1][j+1]==ch))
	{
		func(grid,i+1,j+1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i+1<n)&&(!visited[i+1][j])&&(grid[i+1][j]==ch))
	{
		func(grid,i+1,j,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i+1<n)&&(j-1>=0)&&(!visited[i+1][j-1])&&(grid[i+1][j-1]==ch))
	{
		func(grid,i+1,j-1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((j-1>=0)&&(!visited[i][j-1])&&(grid[i][j-1]==ch))
	{
		func(grid,i,j-1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i-1>=0)&&(j-1>=0)&&(!visited[i-1][j-1])&&(grid[i-1][j-1]==ch))
	{
		func(grid,i-1,j-1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i-1>=0)&&(!visited[i-1][j])&&(grid[i-1][j]==ch))
	{
		func(grid,i-1,j,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
	if((i-1>=0)&&(j+1<m)&&(!visited[i-1][j+1])&&(grid[i-1][j+1]==ch))
	{
		func(grid,i-1,j+1,n,m,visited,str,idx+1,size,ans);
		if(ans)
		{
			return ;
		}
	}
}
bool isPresent(vector<string> &grid,string str,int n)
{
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=new bool[n];
		for(int j=0;j<n;j++)
		{
			visited[i][j]=false;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]==str[0])
			{
				bool ans=false;
				func(grid,i,j,n,n,visited,str,0,str.size(),ans);
				if(ans)
				{
					return true;
				}
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						visited[i][j]=false;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	set<string> dict;
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		dict.insert(str);
	}
	int m;
	cin>>m;
	vector<string> grid;
	for(int i=0;i<m;i++)
	{
		cin>>str;
		grid.push_back(str);
	}
	for(auto it=(dict.begin());it!=dict.end();it++)
	{
		str=(*it);
		if(isPresent(grid,str,m))
		{
			cout<<str<<' ';
		}
	}
}




