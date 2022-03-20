https://www.interviewbit.com/problems/inversions/

void ins(int *bit,int i,int n)
{
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i]++;
    }
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
int inversionCount(vector<int> &a, int n)
{
    set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    unordered_map<int,int> mp;
    int val=0;
    for(auto it=st.begin();it!=st.end();it++)
    {
        mp[(*it)]=++val;
    }
    int *bit=new int[val+1];
    for(int i=0;i<=val;i++){
        bit[i]=0;
    }
    int ans=0;
    ins(bit,mp[a[n-1]],val);
    for(int i=n-2;i>=0;i--)
    {
        int cur=mp[a[i]];
        ans=ans+query(bit,cur-1);
        ins(bit,cur,val);
    }
    return ans;
}
int Solution::countInversions(vector<int> &A) {
    return inversionCount(A,A.size());
}

