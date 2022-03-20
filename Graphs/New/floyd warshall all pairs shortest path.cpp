There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        int **a=new int*[n];
        for(int i=0;i<n;i++)
        {
            a[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                a[i][j]=0;
            }
        }
        int e=edges.size();
        for(int i=0;i<e;i++)
        {
            a[edges[i][0]][edges[i][1]]=edges[i][2];
            a[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0&&(i!=j))
                {
                    a[i][j]=INT_MAX;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if((a[i][k]!=INT_MAX)&&(a[j][i]!=INT_MAX)&&a[j][k]>(a[j][i]+a[i][k]))
                    {
                        a[j][k]=a[j][i]+a[i][k];
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
        int smallestNumber=INT_MAX,ans=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if((i!=j)&&a[i][j]<=d)
                {
                    cnt++;
                }
            }
            cout<<"cnt:"<<cnt<<endl;
            if(smallestNumber>=cnt)
            {
                ans=i;
                smallestNumber=cnt;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& vec, int x) {
        int **edges=new int*[n];
        for(int i=0;i<n;i++)
        {
            edges[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                edges[i][j]=0;
            }
        }
        int m=vec.size();
        for(int i=0;i<m;i++)
        {
            int a=vec[i][0],b=vec[i][1],c=vec[i][2];
            edges[a][b]=c;
            edges[b][a]=c;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(edges[i][j]==0&&(i!=j))
                {
                    edges[i][j]=INT_MAX;
                }
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if((edges[i][k]!=INT_MAX)&&(edges[k][j]!=INT_MAX)&&edges[i][j]>(edges[i][k]+edges[k][j]))
                    {
                        edges[i][j]=edges[i][k]+edges[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<(edges[i][j])<<' ';
            }
            cout<<endl;
        }
//        int ans=-1,smallest=INT_MAX;
//        for(int i=n-1;i>=0;i--)
//        {
//            int counter=0;
//            for(int j=0;j<n;j++)
//            {
//                if(edges[i][j]<=x)
//                {
//                    counter++;
//                }
//            }
//            if(counter<smallest)
//            {
//                smallest=counter;
//                ans=i;
//                cout<<"counter:"<<counter<<",ans:"<<ans<<endl;
//            }
//        }
        return ans;
    }
};


