#include <bits/stdc++.h>
using namespace std;
struct node{
  	int rat1,rat2,index;  
};
bool comparator(node a,node b)
{
    if(a.rat1!=b.rat1)
    {
    	return a.rat1<b.rat1;    
    }
    return a.rat2<b.rat2;
}
int query(int *bit,int i)
{
    int cnt=0;
    for(;i>0;i-=(i&(-i)))
    {
        cnt+=bit[i];
    }
    return cnt;
}
void ins(int *bit,int i,int n)
{
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i]++;
    }
}
int main()
{
    int n;
    cin>>n;
    node *a=new node[n];
    int size=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].rat1>>a[i].rat2;
        a[i].index=i;
        size=max(size,a[i].rat2);
    }
    sort(a,a+n,comparator);
    int *bit=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        bit[i]=0;
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;)
    {
    	node cur=a[i];
        int k=i+1;
        while(a[k].rat1==cur.rat1&&(a[k].rat2==cur.rat2))
        {
            k++;
        }
        for(int x=i;x<k;x++)
        {
            int temp=query(bit,a[x].rat2);
            ans[a[x].index]=temp;
        }
        for(int x=i;x<k;x++)
        {
            ins(bit,a[x].rat2,size);
        }
        i=k;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}














