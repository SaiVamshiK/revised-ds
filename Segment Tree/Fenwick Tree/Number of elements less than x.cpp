void insert(int *bit,int idx,int size)
{
    for(;idx<=size;idx+=(idx&(-idx)))
    {
        bit[idx]++;
    }
}
int query(int *bit,int idx)
{
    int ans=0;
    for(;idx>0;idx-=(idx&(-idx)))
    {
        ans+=bit[idx];
    }
    return ans;
}
int countOfElements(int a[], int n, int x) 
{
    int size=pow(10,5);
    int *bit=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        bit[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        insert(bit,a[i],size);
    }
    int ans=query(bit,x);
    
}
