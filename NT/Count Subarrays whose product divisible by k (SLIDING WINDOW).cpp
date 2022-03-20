#include<bits/stdc++.h>
using namespace std;
void fillMap(unordered_map<int,int> &k_map,int n)
{
    for(int i=2;(i*i)<=n;i++)
    {
        if((n%i)==0)
        {
            int cnt=0,cur=i;
            while((n%i)==0)
            {
                n=n/i;
                cnt++;
            }
            k_map[cur]=cnt;
        }
    }
    if(n!=1)
    {
        k_map[n]=1;
    }
}
void fillCurMap(unordered_map<int,int> &cur_map,int n)
{
    for(int i=2;(i*i)<=n;i++)
    {
        if((n%i)==0)
        {
            int cnt=0,cur=i;
            while((n%i)==0)
            {
                n=n/i;
                cnt++;
            }
            cur_map[cur]+=cnt;
        }
    }
    if(n!=1)
    {
        cur_map[n]++;
    }
}
void removeElemMap(unordered_map<int,int> &cur_map,int n)
{
    for(int i=2;(i*i)<=n;i++)
    {
        if((n%i)==0)
        {
            int cnt=0,cur=i;
            while((n%i)==0)
            {
                n=n/i;
                cnt++;
            }
            cur_map[cur]-=cnt;
        }
    }
    if(n!=1)
    {
        cur_map[n]--;
    }
}
bool isOk(unordered_map<int,int> cur_map,unordered_map<int,int> k_map)
{
    for(auto it=(k_map.begin());it!=(k_map.end());it++)
    {
        int elem=(it->first),cnt=(it->second);
        auto itr=cur_map.find(elem);
        if(itr==cur_map.end())
        {
            return false;
        }
        if((itr->second)<cnt)
        {
            return false;
        }
    }
    return true;
}
int main(){
	int n,k;
    cin>>n>>k;
    unordered_map<int,int> k_map;
    fillMap(k_map,k);
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    unordered_map<int,int> cur_map;
    int i=0,j=0;
    int ans=0;
    while(j<n)
    {
        int elem=a[j];
        fillCurMap(cur_map,elem);
        if(!isOk(cur_map,k_map))
        {
            j++;
        }else{
			while(isOk(cur_map,k_map))
            {
                ans+=(n-j);
                removeElemMap(cur_map,a[i]);
                i++;
            }
            j++;
        }
    }
    cout<<ans;
	return 0;
}



















