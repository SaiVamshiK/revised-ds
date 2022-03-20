int triangleInGraph(int graph[][100],int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(graph[i][j]&&(graph[j][k])&&(graph[k][i]))
                {
                    cnt++;
                }
            }
        }
    }
    return cnt/6;
}
***********************************
 // for directed graph make cnt/3;
***********************************

