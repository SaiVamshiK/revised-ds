
1. You are given a string containing only 0's and 1's.
2. You have to find the length of substring which is having maximum difference of number of 0s and number of 1s i.e 
	(Number of 0's - Number of 1's).
3. If there are all 1's present in the given string, then print '-1'.

REPLACING 1 WITH -1 AND 0 WITH 1 WE WOULD BE GETTING AN ARRAY WHERE A SUBARRAY SUM REPRESENTS THE DIFF IN COUNT OF ZEROS AND ONES
OF THE STRING

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            a[i]=1;
        }else{
            a[i]=-1;
        }
    }
    int maxVal=INT_MIN,curSum=0;
    for(int i=0;i<n;i++)
    {
        curSum+=a[i];
        maxVal=max(maxVal,curSum);
        if(curSum<0)
        {
            curSum=0;
        }
    }
    cout<<maxVal;
}
