
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

int Solution::colorful(int n) {
    vector<int> a;
    while(n>0)
    {
        int val=n%10;
        a.push_back(val);
        n=n/10;
    }
    unordered_map<int,int> mp;
    n=a.size();
    for(int i=0;i<n;i++)
    {
        int val=a[i];
        mp[val]++;
        if(mp[val]>1)
        {
            return 0;
        }
        for(int j=i+1;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            val=val*a[j];
            mp[val]++;
            if(mp[val]>1)
            {
                return 0;
            }
        }
    }
    return 1;
}

