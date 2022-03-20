#include<bits/stdc++.h>
using namespace std;
int main()
{
	int friends,t;
	cin>>friends>>t;
	string x,y;
	int amt;
	unordered_map<string,int> mp;
	for(int i=0;i<t;i++)
	{
		cin>>x>>y>>amt;
		mp[x]-=amt;
		mp[y]+=amt;
	}
	multiset<pair<int,string>> m;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		string cur_name=it->first;
		int cur_cost=it->second;
		if(cur_cost!=0)
        {
            m.insert({cur_cost,cur_name});
        }
	}
    int total_transactions=0;
	while(!m.empty())
	{
        total_transactions++;
		auto it1=m.begin();
		auto it2=m.end();
		it2--;
		int amt1=it1->first;
		int amt2=it2->first;
		string name1=it1->second;
		string name2=it2->second;
		m.erase(it1);
		m.erase(it2);
		int temp=min(abs(amt1),amt2);
		if(abs(amt1)>amt2)
		{
			int ins=amt1+temp;
			m.insert({ins,name1});
		}else if(abs(amt)<amt2)
		{
			int ins=amt2-temp;
			m.insert({ins,name2});
		}
        cout<<(name1)<<" has to pay "<<(temp)<<" to "<<(name2)<<endl;
	}
    cout<<"Total Transactions:"<<total_transactions<<endl;
}













