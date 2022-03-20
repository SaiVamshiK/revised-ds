
decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000

***********************************		SEE THIS APPROACH		***********************************
#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
struct Node{
  	int xi,yi,fi;  
};
ll dist(int x1,int y1,int x2,int y2)
{
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
int main()
{
    int n;
    cin>>n;
    Node *a=new Node[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].xi>>a[i].yi>>a[i].fi;
    }
    ll *dp=new ll[n];
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        ll max_happy=INT_MIN;
        for(int j=i+1;j<n;j++)
        {
        	ll cur;
            cur=a[j].fi-dist(a[i].xi,a[i].yi,a[j].xi,a[j].yi)+dp[j];
            max_happy=max(max_happy,cur);
        }
        dp[i]=max_happy;
    }
    cout.precision(6);
    dp[0]+=a[0].fi;
    cout<<fixed<<(dp[0])<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
ll dist(int x1,int y1,int x2,int y2)
{
    return (sqrt((pow(x2-x1,2))+(pow(y2-y1,2))));
}
int main()
{
    int n;
    cin>>n;
    int x[n],y[n],f[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>f[i];
    }
    ll *dp=new ll[n];
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        dp[i]=f[n-1]-dist(x[i],y[i],x[n-1],y[n-1]);
        for(int inter=i+1;inter<(n-1);inter++)
        {
            dp[i]=max(dp[i],f[inter]+dp[inter]-dist(x[i],y[i],x[inter],y[inter]));
        }
    }
    cout.precision(6);
    cout<<fixed<<dp[0]+f[0];
    return 0;
}
























