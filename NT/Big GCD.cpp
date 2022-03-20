
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.

#include<bits/stdc++.h>
using namespace std;
int func(string b,int m,int n)
{
    if(n==1)
    {
        int last=b[n-1]-'0';
        return (last%m);
    }
    int last=b[n-1]-'0';
    int x=func(b,m,n-1);
    return (((x*(10%m))%m)+((last%m)))%m;
}
int gcd(int a,int b){
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
	while(t--)
    {
        int a;
        cin>>a;
        string b;
        cin>>b;
        if(a==0)
        {
            cout<<b<<endl;
            continue;
        }
        int temp=func(b,a,b.size());
        cout<<gcd(a,temp)<<endl;
    }
	return 0;
}
