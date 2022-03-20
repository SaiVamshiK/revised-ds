FOR INDIAN COIN CHANGE PROBLEM GREEDY TECHNIQUE WORKS BUT FOR OTHER CURRENCIES LIKE 1,7,10 IT DOES NOT WORK
DP ALWAYS WORKS THOUGH
FOR 1,7,10
IF REQUIRED SUM=15
BY GREEDY WE WOULD HAVE PICKED ONE 10 COIN AND FIVE 1 COINS
WHICH IS NOT THE MIN NO. OF COINS
AS 7+7+1 IS THE ANSWER

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[9]={ 1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int sum;
	cin>>sum;
	int cnt=0;
	for(int i=8;i>=0;i--)
	{
		int cur_coin=a[i];
		while(true)
		{
			if((sum-(cur_coin))<0)
			{
				break;
			}
			sum=sum-(cur_coin);
			cnt++;
		}
	}
	cout<<cnt;
}
