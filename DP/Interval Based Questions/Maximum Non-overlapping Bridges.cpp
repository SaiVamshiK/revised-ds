
1. You are given a number n, representing the number of bridges on a river.
2. You are given n pair of numbers, representing the north bank and south bank co-ordinates of each bridge.
3. You are required to print the count of maximum number of non-overlapping bridges.
Input Format
A number n
.. n pair of number each on a separate line (and pair separated by space)
Output Format
A number representing the count of maximum number of non-overlapping bridges.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node {
  ll nb;
  ll sb;
};
bool comparator(Node a, Node b)
{
    if(a.nb==b.nb)
    {
        return a.sb<b.sb;
    }
  return a.nb < b.nb;
}
int main()
{
  ll n;
  cin >> n;
  Node* a = new Node[n];
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i].nb >> a[i].sb;
  }
  sort(a, a + n, comparator);
  ll* dp = new ll[n];
  dp[0] = 1;
  for (ll i = 1; i < n; i++)
  {
    ll maxVal = INT_MIN;
    for (ll j = i - 1; j >= 0; j--)
    {
      if (a[j].sb <= a[i].sb)
      {
        maxVal = max(maxVal, dp[j] + 1);
      }
    }
    if (maxVal != INT_MIN)
    {
      dp[i] = maxVal;
    } else {
      dp[i] = 1;
    }
  }
  ll ans = 1;
  for (ll i = 0; i < n; i++)
  {
    ans = max(ans, dp[i]);
  }
  cout << ans;
}




