
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.

#include <bits/stdc++.h>
using namespace std;
int kadane(int *a,int n)
{
    int cur_sum=0,max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cur_sum+=a[i];
        max_sum=max(max_sum,cur_sum);
        if(cur_sum<0)
        {
            cur_sum=0;
        }
    }
    return max_sum;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int *arr=new int[n];
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int start=0;start<n;start++)
        {
            arr[start]=a[start][i];
        }
        ans=max(ans,kadane(arr,n));
        for(int j=i+1;j<m;j++)
        {
            for(int start=0;start<n;start++)
            {
                arr[start]=arr[start]+a[start][j];
            }
            ans=max(ans,kadane(arr,n));
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int kadane(int *a,int n)
{
    int msf=INT_MIN,meh=0;
    for(int i=0;i<n;i++)
    {
        meh+=a[i];
        if(meh<a[i])
        {
            meh=a[i];
        }
        msf=max(msf,meh);
    }
    return msf;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=INT_MIN;
    int *temp=new int[n];
    for(int l=0;l<m;l++)
    {
        for(int i=0;i<n;i++)
        {
            temp[i]+=(a[i][l]);
        }
        for(int r=l+1;r<m;r++)
        {
            int kad_ans=kadane(temp,n);
            ans=max(ans,kad_ans);
            for(int i=0;i<n;i++)
            {
                temp[i]+=(a[i][r]);
            }
        }
        for(int i=0;i<n;i++)
        {
            temp[i]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}





















