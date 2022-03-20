
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9 
Sample Output:
3
9

#include<bits/stdc++.h>
using namespace std;
bool isValid(int *a,int n,int k,int val)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int cur=a[i];
        cnt=cnt+(floor(cur/val));
        if(cnt>=k)
        {
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int *a=new int[n];
        int start=1,end=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            end+=a[i];
        }
        int ans=start;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isValid(a,n,k,mid))
            {
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}
