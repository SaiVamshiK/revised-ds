Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, 
eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

const int Mod=1e9+7;
int Solution::nchoc(int t, vector<int> &a) {
    int n=a.size();
    long long ans=0;
    priority_queue<long long> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }
    while(t--)
    {
        long long x=pq.top();
        ans+=(pq.top());
        ans%=Mod;
        pq.pop();
        pq.push(floor(x/2));
    }
    return ans;
}

