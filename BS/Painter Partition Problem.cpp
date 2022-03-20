const int mod=10000003;
bool isValid(int timeVal,vector<int > &a,int n,int x)
{
    int cnt=1;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur=cur+a[i];
        if(cur>timeVal)
        {
            cnt++;
            cur=0;
            if((cur+a[i])<=timeVal)
            {
                cur=cur+a[i];
            }else{
                return false;
            }
        }
        if(cnt>x) 
        {
            return false;
        }
    }
    return true;
}
int Solution::paint(int x, int B, vector<int> &a) {
    int start=INT_MIN,end=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        start=max(start,a[i]);
        end+=a[i];
    }
    int ans;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(isValid(mid,a,n,x))
        {
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ((long long)ans*B)%mod;
}

