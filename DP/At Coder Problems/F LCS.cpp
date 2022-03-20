#include<bits/stdc++.h>
using namespace std;
string lcs(int x, int y, string s1, string s2){
    int n=s1.size(),m=s2.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=1;j<=m;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans="";
    while(i!=0&&(j!=0))
    {
    	if(s1[i-1]==s2[j-1])
    	{
    		ans.push_back(s1[i-1]);
    		i--;
    		j--;
		}else{
			if(dp[i-1][j]>(dp[i][j-1]))
			{
				i--;
			}else{
				j--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	string s,t;
	cin>>s>>t;
	cout<<lcs(s.size(),t.size(),s,t);
}

