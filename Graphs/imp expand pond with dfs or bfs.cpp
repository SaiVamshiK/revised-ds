


You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.
Input Format

The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.
Constraints

1 = N,M = 1000 There is at least one dry cell and one cell filled with water in the matrix.
Output Format

Print a single integer representing the largest possible size of the pond.


#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int i,int j,int n,int m,bool **visited,int **component_matrix,int component,int &size)
{
	visited[i][j]=true;
	component_matrix[i][j]=component;
	size++;
	if((i+1<n)&&(edges[i+1][j]==1)&&(!visited[i+1][j]))
	{
		dfs(edges,i+1,j,n,m,visited,component_matrix,component,size);
	}
	if((j+1<m)&&(edges[i][j+1]==1)&&(!visited[i][j+1]))
	{
		dfs(edges,i,j+1,n,m,visited,component_matrix,component,size);
	}
	if((i-1>=0)&&(edges[i-1][j]==1)&&(!visited[i-1][j]))
	{
		dfs(edges,i-1,j,n,m,visited,component_matrix,component,size);
	}
	if((j-1>=0)&&(edges[i][j-1]==1)&&(!visited[i][j-1]))
	{
		dfs(edges,i,j-1,n,m,visited,component_matrix,component,size);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **edges=new int*[n];
	int **component_matrix=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[m];
		component_matrix[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			edges[i][j]=0;
			component_matrix[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>edges[i][j];
		}
	}
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			visited[i][j]=false;
		}
	}
	int component=0;
	vector<int> component_size;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(edges[i][j]==1&&(!visited[i][j]))
			{
				int size=0;
				dfs(edges,i,j,n,m,visited,component_matrix,component,size);
				component++;
                component_size.push_back(size);
			}
		}
	}
    
    int ans=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(edges[i][j]==0)
			{
				set<int> adjacent_components;
                if((i+1<n)&&(component_matrix[i+1][j]!=-1))
                {
                    adjacent_components.insert(component_matrix[i+1][j]);
                }
                if((j+1<m)&&(component_matrix[i][j+1]!=-1))
                {
                    adjacent_components.insert(component_matrix[i][j+1]);
                }
                if((i-1>=0)&&(component_matrix[i-1][j]!=-1))
                {
                    adjacent_components.insert(component_matrix[i-1][j]);
                }
                if((j-1>=0)&&(component_matrix[i][j-1]!=-1))
                {
                    adjacent_components.insert(component_matrix[i][j-1]);
                }
				int temp_ans=1;
				for(auto it=adjacent_components.begin();it!=adjacent_components.end();it++)
				{
					int temp_component_no=(*it);
					temp_ans+=(component_size[temp_component_no]);
				}
				ans=max(ans,temp_ans);
			}
		}
	}
	cout<<ans;
}







// Other
#include<bits/stdc++.h>
using namespace std;
void dfs(int **board,int n,int m,int i,int j,bool **visited,int component,int &component_size,int **comp_matrix)
{
	visited[i][j]=true;
	component_size++;
	comp_matrix[i][j]=component;
	if((i+1<n)&&(board[i+1][j]!=0)&&(!visited[i+1][j]))
	{
		dfs(board,n,m,i+1,j,visited,component,component_size,comp_matrix);
	}
	if((i-1>=0)&&(board[i-1][j]!=0)&&(!visited[i-1][j]))
	{
		dfs(board,n,m,i-1,j,visited,component,component_size,comp_matrix);
	}
	if((j+1<m)&&(board[i][j+1]!=0)&&(!visited[i][j+1]))
	{
		dfs(board,n,m,i,j+1,visited,component,component_size,comp_matrix);
	}
	if((j-1>=0)&&(board[i][j-1]!=0)&&(!visited[i][j-1]))
	{
		dfs(board,n,m,i,j-1,visited,component,component_size,comp_matrix);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **board=new int*[n];
	int **comp_matrix=new int*[n];
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		board[i]=new int[m];
		comp_matrix[i]=new int[m];
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			board[i][j]=0;
			comp_matrix[i][j]=-1;
			visited[i][j]=false;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>board[i][j];
		}
	}
	int component=0;
	vector<int> each_comp_size;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j]&&(board[i][j]==1))
			{
				int component_size=0;
				dfs(board,n,m,i,j,visited,component,component_size,comp_matrix);
				each_comp_size.push_back(component_size);
				component++;
			}
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]==0)
			{
				// i+1,j
				set<int> temp;
				int q=1;
				if(i+1<n&&(comp_matrix[i+1][j]!=-1))
				{
					temp.insert(comp_matrix[i+1][j]);
				}
				// i-1,j
				if((i-1>=0)&&(comp_matrix[i-1][j]!=-1))
				{
					temp.insert(comp_matrix[i-1][j]);
				}
				// i,j+1
				if((j+1<m)&&(comp_matrix[i][j+1]!=-1))
				{
					temp.insert(comp_matrix[i][j+1]);
				}
				// i,j-1
				if((j-1>=0)&&(comp_matrix[i][j-1]!=-1))
				{
					temp.insert(comp_matrix[i][j-1]);
				}
				for(auto it=temp.begin();it!=temp.end();it++)
				{
					q=q+each_comp_size[(*it)];
				}
				ans=max(ans,q);
			}
		}
	}
	cout<<ans;
}





















