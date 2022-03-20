#include <bits/stdc++.h>
using namespace std;
struct node{
  	int start,end,index;  
};
bool comparator(node a,node b)
{
    return a.end<b.end;
}
void ins(int *bit,int i,int n,int val)
{
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i]+=val;
    }
}
int query(int *bit,int i)
{
    int ans=0;
    for(;i>0;i-=(i&(-i)))
    {
        ans+=bit[i];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    int size=n;
    node *queries=new node[q];
    int *bit=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        bit[i]=0;
    }
    for(int i=0;i<q;i++)
    {
    	cin>>queries[i].start>>queries[i].end;
        queries[i].index=i;
    }
    int w=pow(10,6);
    int *last=new int[w+1];
    for(int i=0;i<=w;i++)
    {
        last[i]=-1;
    }
    sort(queries,queries+q,comparator);
    int k=0;
    int total=0;
    vector<int> ans(q,-1);
    for(int i=1;i<=n;i++)
    {
        if(last[a[i]]!=-1)
        {
			int x=last[a[i]];
            ins(bit,x,size,-1);
            ins(bit,i,size,1);
            last[a[i]]=i;
        }else{
         	ins(bit,i,size,1);
            last[a[i]]=i;
            total++;
        }
        while((k<q)&&queries[k].end==i)
        {
            int temp=query(bit,queries[k].start-1);
            ans[queries[k].index]=total-temp;
            k++;
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}











