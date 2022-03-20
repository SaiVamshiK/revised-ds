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
            k_map[cur]+=cnt;
        }
    }
    if(n!=1)
    {
        k_map[n]++;
    }
}
void fillCurMap(unordered_map<int,int> &k_map,int n)
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
        	if(k_map.find(cur)!=k_map.end())    
            {
                k_map[cur]-=cnt;
            }
        }
    }
    if(n!=1)
    {
        if(k_map.find(n)!=k_map.end())
        {
            k_map[n]--;
        }
    }
}
void removeElemMap(unordered_map<int,int> &k_map,int n)
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
        	if(k_map.find(cur)!=k_map.end())    
            {
                k_map[cur]+=cnt;
            }
        }
    }
    if(n!=1)
    {
        if(k_map.find(n)!=k_map.end())
        {
            k_map[n]++;
        }
    }
}
bool isOk(unordered_map<int,int> k_map)
{
    for(auto it=(k_map.begin());it!=(k_map.end());it++)
    {
        int elem=(it->first),cnt=(it->second);
     	if(cnt>0)   
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
    int i=0,j=0;
    int ans=0;
    while(j<n)
    {
        int elem=a[j];
        fillCurMap(k_map,elem);
        if(!isOk(k_map))
        {
            j++;
        }else{
			while(isOk(k_map))
            {
                ans+=(n-j);
                removeElemMap(k_map,a[i]);
                i++;
            }
            j++;
        }
    }
    cout<<ans;
	return 0;
}



















