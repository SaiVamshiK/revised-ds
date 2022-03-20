
You are given an array A containing N integers. The special product of each ith integer in this array 
is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s 
are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s 
are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

const int mod=1e9+7;
typedef long long ll;
int Solution::maxSpecialProduct(vector<int> &a) {
    ll n=a.size();
    ll *ngl=new ll[n];
    ll *ngr=new ll[n];
    stack<pair<ll,ll>> st;
    for(ll i=0;i<n;i++)
    {
        if(st.empty())
        {
            ngl[i]=-1;
            st.push({a[i],i});
        }else{
            while((!st.empty())&&(st.top().first<=a[i]))
            {
                st.pop();
            }
            if(st.empty())
            {
                ngl[i]=-1;
            }else{
                ngl[i]=st.top().second;
            }
            st.push({a[i],i});
        }
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(ll i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            ngr[i]=n;
            st.push({a[i],i});
        }else{
            while((!st.empty())&&(st.top().first<=a[i]))
            {
                st.pop();
            }
            if(st.empty())
            {
                ngr[i]=n;
            }else{
                ngr[i]=st.top().second;
            }
            st.push({a[i],i});
        }
    }
    ll ans=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        if(ngl[i]==-1)
        {
            ngl[i]=0;
        }
        if(ngr[i]==n)
        {
            ngr[i]=0;
        }
        ans=max(ans,ngl[i]*ngr[i]);
        ans%=mod;
    }
    return ans;
}

