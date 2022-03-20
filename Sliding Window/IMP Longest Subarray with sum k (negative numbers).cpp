Given a linked list containing N integers and an integer K. Your task is to find the length of the longest sub list with sum of the elements equal to the given value K.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two Integers N and K and the second line contains N space separated elements of the list.
Output:
For each test case, print the required length of the longest sub list in new line. If no such sub array can be formed print 0.

ip:
3
6 15
10 5 2 7 1 9
6 -5
-5 8 -14 2 4 12
3 6
-1 2 3
op:
4
5
0

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans=INT_MIN;
        int sum=0;
        unordered_map<int,int> mp;
        // {sum,index}
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            if(sum==k)
            {
                ans=max(ans,i+1);
            }
            if(mp.find(sum-k)!=mp.end())
            {
                int idx=mp[sum-k];
                idx++;
                ans=max(ans,i-idx+1);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
        }
        if(ans==INT_MIN)
        {
            cout<<0<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
}






















