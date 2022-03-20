#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int *a=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int *pre=new int[n];
		int *suf=new int[n];
		pre[0]=a[0];
		for(int i=1;i<n;i++)
		{
			pre[i]=gcd(a[i],pre[i-1]);
		}
		suf[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--)
		{
			suf[i]=gcd(a[i],suf[i+1]);
		}
		int l,r;
		while(q--)
		{
			cin>>l>>r;
			l--;r--;
            if(l!=0&&(r!=(n-1)))
            {
                cout<<(gcd(pre[l-1],suf[r+1]))<<endl;
            }
			else if(l!=0)
            {
                cout<<pre[l-1]<<endl;
            }else if(r!=(n-1))
            {
                cout<<suf[r+1]<<endl;
            }else{
                cout<<0<<endl;
            }
		}
	}
}


