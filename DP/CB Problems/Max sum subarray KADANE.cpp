class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int meh=0,msf=INT_MIN;
        for(int i=0;i<n;i++)
        {
            meh+=a[i];
            if(meh<a[i])
            {
                meh=a[i];
            }
            msf=max(msf,meh);
        }
        return msf;
    }
};
