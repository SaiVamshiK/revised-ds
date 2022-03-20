#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin>>n;
    int ans=0;
    int cnt=0;
    // Counting the number of factors
    for(int i=1;i<=n;i++)
    {
        int cur=i;
        for(int j=1;(j*j)<=cur;j++)
        {
            if((j*j)==cur)
            {
                cnt++;
            }else{
                cnt+=2;
            }
        }
        if(cnt==2)
        {
            ans++;
        }
    }
    cout<<ans;
	return 0;
}
