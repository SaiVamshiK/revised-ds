
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &a) {
    ll n=a.size();
    ll sumSq=0,actSq=0;
    for(ll i=1;i<=n;i++)
    {
        sumSq+=((ll)pow(i,2));
    }
    for(ll i=0;i<n;i++)
    {
        actSq+=((ll)pow(a[i],2));
    }
    ll diff1=sumSq-actSq;
    ll sum=0,act=0;
    for(ll i=1;i<=n;i++)
    {
        sum+=(ll)i;
    }
    for(ll i=0;i<n;i++)
    {
        act+=(ll)a[i];
    }
    ll diff2=sum-act;
    ll m=((ll)diff1/diff2);
    m+=(diff2);
    m=m/2;
    ll d=m-diff2;
    vector<int> ans;
    ans.push_back(d);
    ans.push_back(m);
    return ans;
}

