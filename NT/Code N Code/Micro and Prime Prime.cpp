
Micro just learned about prime numbers. 
But he quickly got bored of them, so he defined a new kind of numbers and called them Prime Prime Numbers. 
A number X is Prime Prime if number of prime numbers from 1 to X (inclusive) are prime. 
Now he wants to find out the number of Prime Prime numbers from L to R (inclusive). 
Help Micro with it.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
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
    int *arr=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        arr[i]=0;
    }
    arr[2]=1;
    for(int i=3;i<=size;i++)
    {
        arr[i]+=arr[i-1];
        if(sieve[i])
        {
            arr[i]++;
        }
    }
    int *arr1=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        arr1[i]=0;
    }
    arr1[2]=0;
    for(int i=3;i<=size;i++)
    {
        int total_primes_till_now=arr[i];
        if(sieve[total_primes_till_now])
        {
            arr1[i]++;
        }
    }
    for(int i=3;i<=size;i++)
    {
        arr1[i]+=arr1[i-1];
    }
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<(arr1[r]-arr1[l-1])<<endl;
    }
}

