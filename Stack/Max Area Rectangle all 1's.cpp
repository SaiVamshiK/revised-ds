

Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0 
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.

/*You are required to complete this method*/
class Solution{
  public:
    int findMaxHist(int a[MAX][MAX],int row,int n)
    {
        int ans=INT_MIN;
        int *nsl=new int[n];
        int *nsr=new int[n];
        stack<pair<int,int> > st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                nsl[i]=-1;
                st.push({a[row][i],i});
            }else{
                while((!st.empty())&&(st.top().first>=a[row][i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    nsl[i]=-1;
                    st.push({a[row][i],i});
                }else{
                    nsl[i]=st.top().second;
                    st.push({a[row][i],i});
                }
            }
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                nsr[i]=n;
                st.push({a[row][i],i});
            }else{
                while((!st.empty())&&(st.top().first>=a[row][i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    nsr[i]=n;
                    st.push({a[row][i],i});
                }else{
                    nsr[i]=st.top().second;
                    st.push({a[row][i],i});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            nsl[i]++;
            nsr[i]--;
            ans=max(ans,(nsr[i]-nsl[i]+1)*(a[row][i]));
        }
        return ans;
    }
    int maxArea(int a[MAX][MAX], int n, int m) {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!=0)
                {
                    a[i][j]=a[i][j]+a[i-1][j];
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,findMaxHist(a,i,m));
        }
        return ans;
    }
};

