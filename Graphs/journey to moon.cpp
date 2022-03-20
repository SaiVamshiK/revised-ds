
The member states of the UN are planning to send 2

people to the moon. They want them to be from different countries. 
You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. 
Determine how many pairs of astronauts from different countries they can choose from.

For example, we have the following data on 2 pairs of astronauts, and 4 astronauts total, numbered
through

.

1   2
2   3

Sample Input 0

5 3
0 1
2 3
0 4

Sample Output 0

6





#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
int get(int i,int *parent)
{
    if(i==parent[i])
    {
        return i;
    }
    return parent[i]=get(parent[i],parent);
}
int journeyToMoon(int n, vector<vector<int>> a) {
    int *rank=new int[n];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        rank[i]=1;
        parent[i]=i;
    }
    int e=a.size();
    for(int i=0;i<e;i++)
    {
        int si=a[i][0],ei=a[i][1];
        int par_si=get(si,parent),par_ei=get(ei,parent);
        if(par_si!=par_ei)
        {
            int rank_si=rank[par_si],rank_ei=rank[par_ei];
            if(rank_si<=rank_ei)
            {
                parent[par_si]=par_ei;
                rank[par_ei]+=rank[par_si];
            }else{
                parent[par_ei]=par_si;
                rank[par_si]+=rank[par_ei];
            }
        }
    }
    long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(n-rank[(get(i,parent))]);
    }
    return ans/2;
}



