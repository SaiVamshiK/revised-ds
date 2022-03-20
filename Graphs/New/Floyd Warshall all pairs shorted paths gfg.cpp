
The problem is to find shortest distances between every pair of vertices in a given edge 
weighted directed Graph. The Graph is represented as adjancency matrix, and the matrix denotes 
the weight of the edegs (if it exists) else -1. Do it in-place.
 

Example 1:

Input: matrix = {{0,25},{-1,0}}
Output: {{0,25},{-1,0}}
Explanation: The shortest distance between
every pair is already given(if it exists).

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&a){
	    int n=a.size(),m=a[0].size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(a[i][j]==-1)
	            {
	                a[i][j]=INT_MAX;
	            }
	        }
	    }
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if((a[i][k]!=INT_MAX)&&(a[k][j]!=INT_MAX)&&a[i][j]>(a[i][k]+a[k][j]))
	                {
	                    a[i][j]=a[i][k]+a[k][j];
	                }
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(a[i][j]==INT_MAX)
	            {
	                a[i][j]=-1;
	            }
	        }
	    }
	}
};
