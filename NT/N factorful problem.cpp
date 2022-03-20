
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].


#include<bits/stdc++.h>
using namespace std;

int main(){
	int size=pow(10,6);
    bool *sieve=new bool[size+1];
    for(int i=0;i<=size;i++)
    {
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;(i*i)<=size;i++)
    {
        if(sieve[i])
        {
            int elem=i,mul=i;
            while((elem*mul)<=size)
            {
                sieve[(elem*mul)]=false;
                mul++;
            }
        }
    }
    vector<int> primes;
    for(int i=2;i<=size;i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
        }
    }
    int *arr=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        if(sieve[i])
        {
            arr[i]=1;
        }else{
            arr[i]=0;
        }
    }
    for(int i=0;i<(primes.size());i++)
    {
        int elem=primes[i];
        int mul=2;
        while((elem*mul)<=size)
        {
            arr[(elem*mul)]++;
            mul++;
        }
    }
    int **dp=new int*[11];
    for(int i=0;i<=10;i++)
    {
        dp[i]=new int[size+1];
        for(int j=0;j<=size;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=size;i++)
    {
        dp[arr[i]][i]++;
    }
    for(int i=0;i<=10;i++)
    {
        for(int j=1;j<=size;j++)
        {
            dp[i][j]+=dp[i][j-1];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        cout<<(dp[n][b]-dp[n][a-1])<<endl;
    }
	return 0;
}




































