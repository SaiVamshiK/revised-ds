#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int l;
		cin>>l;
		int **edges=new int*[100];
		for(int i=0;i<100;i++)
		{
			edges[i]=new int[100];
			for(int j=0;j<100;j++)
			{
				edges[i][j]=0;
			}
		}
		int board[100],a,b;
		for(int i=0;i<100;i++)
		{
			board[i]=0;
		}
		for(int i=0;i<l;i++)
		{
			cin>>a>>b;
			a--;b--;
			board[a]+=(b-a);
		}
		int s;
		cin>>s;
		for(int i=0;i<s;i++)
		{
			cin>>a>>b;
			a--;b--;
			board[a]+=(b-a);
		}
		for(int i=0;i<100;i++)
		{
			int cur=i;
			for(int j=1;j<=6;j++)
			{
				int temp=cur+j+board[cur+j];
				if((temp>=0)&&(temp<=99))
				{
					edges[cur][temp]=1;
				}
			}
		}
		bool *visited=new bool[100];
		for(int i=0;i<100;i++)
		{
			visited[i]=false;
		}
		queue<int> q;
		q.push(0);
		visited[0]=true;
		unordered_map<int,int> mp;
		mp[0]=-1;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<100;i++)
			{
				if(edges[x][i]!=0&&(!visited[i]))
				{
					q.push(i);
					visited[i]=true;
					mp[i]=x;
				}
			}
		}
		int cnt=0;
		int x=99;
		if(mp.find(x)==mp.end())
		{
			cout<<"-1"<<endl;
			continue;
		}
		bool done=false;
		while(mp[x]!=-1)
		{
			cnt++;
			x=mp[x];
			if(mp.find(x)==mp.end())
			{
				cout<<"-1"<<endl;
				done=true;
				break;
			}
		}
		if(!done)
		{
			cout<<cnt<<endl;
		}
	}
	return 0;
}


