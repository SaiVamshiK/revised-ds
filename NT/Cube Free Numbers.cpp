
A cube free number is a number who’s none of the divisor is a cube number 
(A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). 
So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc 
(we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. 
So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and 
position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int size=pow(10,6);
    bool *arr=new bool[size+1];
    for(int i=0;i<=size;i++)
    {
        arr[i]=true;
    }
    for(int i=2;(i<=100);i++)
    {
        if(arr[i])
        {
            int elem=pow(i,3);
            int mul=1;
            while((elem*mul)<=size)
            {
                arr[(elem*mul)]=false;
                mul++;
            }
        }
    }
    int *dp=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        dp[i]=-1;
    }
    dp[1]=1;
    int now=1;
    for(int i=2;i<=size;i++)
    {
        if(arr[i])
        {
            now++;
            dp[i]=now;
        }
    }
    int t;
    cin>>t;
    int o=1;
    while(t--)
    {
        int n;
        cin>>n;
        if(dp[n]!=-1)
        {
            cout<<"Case "<<o<<": "<<dp[n]<<endl;
        }else{
            cout<<"Case "<<o<<": Not Cube Free"<<endl;
        }
        o++;
    }
	return 0;
}












