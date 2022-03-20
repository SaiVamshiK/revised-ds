
You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.

Input Format
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints
1 = N,M = 1000 There is at least one dry cell and one cell filled with water in the matrix.

Output Format
Print a single integer representing the largest possible size of the pond.

Sample Input
3 3
0 1 1
0 0 1
0 1 0
Sample Output
5
Explanation
Watering the cell at coordinates [2,2] unites the 2 ponds with sizes 1 and 3, resulting a pond of size 5, including the newly watered cell.

#include<bits/stdc++.h>
using namespace std;
void dfs(int **a,int n,int m,int i,int j,int **comp_matrix,int comp_no,bool **visited,int &len)
{
	len++;
	visited[i][j]=true;
	comp_matrix[i][j]=comp_no;
	if((i+1<n)&&(a[i+1][j]==1)&&(!visited[i+1][j]))
	{
		dfs(a,n,m,i+1,j,comp_matrix,comp_no,visited,len);
	}
	if((j+1<m)&&(a[i][j+1]==1)&&(!visited[i][j+1]))
	{
		dfs(a,n,m,i,j+1,comp_matrix,comp_no,visited,len);
	}
	if((i-1>=0)&&(a[i-1][j]==1)&&(!visited[i-1][j]))
	{
		dfs(a,n,m,i-1,j,comp_matrix,comp_no,visited,len);
	}
	if((j-1>=0)&&(a[i][j-1]==1)&&(!visited[i][j-1]))
	{
		dfs(a,n,m,i,j-1,comp_matrix,comp_no,visited,len);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **a=new int*[n];
	int **comp_matrix=new int*[n];
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		comp_matrix[i]=new int[m];
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			comp_matrix[i][j]=-1;
			visited[i][j]=false;
		}
	}
	int comp_no=0;
	vector<int> comp_size;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==1&&(!visited[i][j]))
			{
				int len=0;
				dfs(a,n,m,i,j,comp_matrix,comp_no,visited,len);
				comp_size.push_back(len);
				comp_no++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0)
			{
				set<int> st;
				if((i+1<n)&&a[i+1][j]==1)
				{
					st.insert(comp_matrix[i+1][j]);
				}
				if((j+1<m)&&a[i][j+1]==1)
				{
					st.insert(comp_matrix[i][j+1]);
				}
				if((j-1>=0)&&a[i][j-1]==1)
				{
					st.insert(comp_matrix[i][j-1]);
				}
				if((i-1>=0)&&a[i-1][j]==1)
				{
					st.insert(comp_matrix[i-1][j]);
				}
				int sum=0;
				for(auto it=st.begin();it!=st.end();it++)
				{
					int cur=((*it));
					sum+=comp_size[cur];
				}
				ans=max(ans,sum+1);
			}
		}
	}
	cout<<ans;
}




