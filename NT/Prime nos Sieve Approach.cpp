#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin>>n;
    bool *sieve=new bool[n+1];
    for(int i=0;i<=n;i++)
    {
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;(i*i)<=n;i++)
    {
        if(sieve[i])
        {
            int cur=i;
            int idx=i;
            while((idx*cur)<=n)
            {
                sieve[(cur*idx)]=false;
                idx++;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<=n;i++)
    {
        if(sieve[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
	return 0;
}
