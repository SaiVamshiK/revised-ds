
***
Splitwise App Algo with output as minimum number of transactions

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int friends,t;
	cin>>friends>>t;
	int x,y,amt;
	int *val=new int[friends];
	for(int i=0;i<friends;i++)
	{
		val[i]=0;
	}
	for(int i=0;i<t;i++)
	{
		cin>>x>>y>>amt;
		val[x]-=amt;
		val[y]+=amt;
	}
	multiset<int> m;
	int total_transactions=0;
	for(int i=0;i<friends;i++)
	{
		if(val[i]!=0)
		{
			m.insert(val[i]);	
		}
	}
	while(!m.empty())
	{
		total_transactions++;
		auto it1=m.begin();
		auto it2=m.end();
		it2--;
		m.erase(it1);
		m.erase(it2);
		int left=(*it1),right=(*it2);
		int temp=min(abs(left),right);
		if(abs(left)>right)
		{
			int ins=left+temp;
			m.insert(ins);	
		}else if(abs(left)<right){
			int ins=right-temp;
			m.insert(ins);
		}
	}
	cout<<"Total transactions:"<<(total_transactions)<<endl;
}
