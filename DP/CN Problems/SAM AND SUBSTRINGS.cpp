
Samantha and Sam are playing a numbers game. Given a number as a string, no leading zeros, 
determine the sum of all integer values of substrings of the string.

Given an integer as a string, sum all of its substrings cast as integers.

Sample Input 0

16
Sample Output 0

23
Explanation 0

The substrings of 16 are 16, 1 and 6 which sum to 23.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll substrings(string s) {
    ll n=s.size();
    ll *dp=new ll[n];
    dp[0]=s[0]-'0';
    for(ll i=1;i<n;i++)
    {
        dp[i]=(( ((dp[i-1]*10)%mod) + (((s[i]-'0')*(i+1))%mod) )%mod);
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans=(((ans%mod)+(dp[i]%mod))%mod);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

