Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like 
to distribute one packet to each of the K children in the village (each packet may contain different number of candies).
 To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith 
packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. 
We can verify that it will be minimum in this way.

***************************		After Sorting it is a sliding window problem		***************************

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll *a=new ll[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll cur_max=INT_MIN;
    ll i=0,j=0;
    ll cur_sum=0;
    ll abs_sum=0;
    ll ans=INT_MAX;
    while(j<n)
    {
        cur_sum+=a[j];
        ll prev_sum=cur_sum-a[j];
        abs_sum+=(abs((j-i)*a[j]-(prev_sum)));
        if((j-i+1)<k)
        {
			j++;
        }else if((j-i+1)==k)
        {
        	ans=min(ans,abs_sum);
            abs_sum-=(abs(((j-i)*a[i])-(cur_sum-a[i])));
            cur_sum-=a[i];
            i++;j++;
        }
    }
    cout<<ans;
    return 0;
}



