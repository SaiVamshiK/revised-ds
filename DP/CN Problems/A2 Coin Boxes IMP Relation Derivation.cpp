
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 = N = 1000000

1 = M = 1000000

1 = L = R = N

1 = Q = 1000000

1 = X = N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4

*********************************************** SEE THIS APPROACH	***********************************************

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *start=new int[n];
    int *end=new int[n];
    for(int i=0;i<n;i++)
    {
        start[i]=0;
        end[i]=0;
    }
    int m;
    cin>>m;
    int l,r;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        l--;r--;
        start[l]++;
        end[r]++;
    }
    int maxCoins=INT_MIN;
    int *a=new int[n];
    a[0]=start[0];
    maxCoins=max(maxCoins,a[0]);
    for(int i=1;i<n;i++)
    {
        a[i]=start[i]+a[i-1]-end[i-1];
        maxCoins=max(maxCoins,a[i]);
    }
    int *dp=new int[maxCoins+1];
    for(int i=0;i<=maxCoins;i++)
    {
        dp[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        dp[a[i]]++;
    }
    for(int i=maxCoins-1;i>=0;i--)
    {
        dp[i]+=dp[i+1];
    }
    int q;
    cin>>q;
    int x;
    while(q--)
    {
        cin>>x;
        if(x>maxCoins)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<dp[x]<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int start[n]={0},end[n]={0};
    int l,r;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        l--;r--;
        start[l]++;
        end[r]++;
    }
    int *dp=new int[n];
    dp[0]=start[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=start[i]-end[i-1]+dp[i-1];
    }
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        arr[dp[i]]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        arr[i]+=arr[i+1];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<arr[x]<<endl;
    }
    return 0;
}














