typedef long long ll;
int Solution::pow(int a, int b, int c) {
    ll x=a,n=b,d=c;
    if(x==0)
    {
        return 0;
    }
    if(n==1)
    {
        return (x+d)%d;
    }
    ll ans=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            ll p=((x*x)+d)%d;
            x=((((p)+d)%d)+d)%d;
            n=n/2;
        }else{
            ll p=((ans*x)+d)%d;
            ans=((((p)+d)%d)+d)%d;
            n--;
        }
    }
    return (ans%d +d)% d;
}

