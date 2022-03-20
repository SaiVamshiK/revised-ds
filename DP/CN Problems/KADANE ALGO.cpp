************************************
KADANE ALGORITHM(MAXIMUM CONTIGOUS SUBARRAY SUM)
************************************
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int cur_sum=0,max_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cur_sum+=a[i];
            max_sum=max(max_sum,cur_sum);
            if(cur_sum<0)
            {
                cur_sum=0;
            }
        }
        return max_sum;
    }
};

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



