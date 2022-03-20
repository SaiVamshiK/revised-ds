
THERE ARE N WHITE AND N BLACK DOTS EQUALLY PLACED ON A LINE.
We need to connect n white dots with n black dots such that the length of the wire used for connection is minimized.
Greedy Approach:
	We connect a white dot with its nearest black dot
	So we sort both the arrays and the corresponding indexes at both arrays for each index would be taken in pairing.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *whites=new int[n];
	int *blacks=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>whites[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>blacks[i];
	}
	sort(whites,whites+n);
	sort(blacks,blacks+n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(abs(whites[i]-blacks[i]));
	}
	cout<<ans;
}
