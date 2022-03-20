
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12

typedef long long ll;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    { 
        ll *nsl=new ll[n];
        ll *nsr=new ll[n];
        stack<pair<ll,ll>> st;
        for(ll i=0;i<n;i++)
        {
            if(st.empty())
            {
                nsl[i]=-1;
                st.push({a[i],i});
            }else{
                while((!st.empty())&&(st.top().first>=a[i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    nsl[i]=-1;
                    st.push({a[i],i});
                }else{
                    nsl[i]=st.top().second;
                    st.push({a[i],i});
                }
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
                nsr[i]=n;
                st.push({a[i],i});
            }else{
                while((!st.empty())&&(st.top().first>=a[i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    nsr[i]=n;
                    st.push({a[i],i});
                }else{
                    nsr[i]=st.top().second;
                    st.push({a[i],i});
                }
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            nsl[i]++;nsr[i]--;
            ans=max(((nsr[i]-nsl[i]+1)*(a[i])),ans);
        }
        return ans;
    }
};



