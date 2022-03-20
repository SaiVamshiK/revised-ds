Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        if(n==0||(n==1)||(n==2))
        {
            return 0;
        }
        int *gl=new int[n];
        int *gr=new int[n];
        gl[0]=0;
        gr[n-1]=0;
        int max_left=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>max_left)
            {
                max_left=a[i];
            }
            gl[i]=max_left;
        }
        int max_right=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>max_right)
            {
                max_right=a[i];
            }
            gr[i]=max_right;
        }
        int ans=0;
        for(int i=1;i<(n-1);i++)
        {
            int val=min(gl[i],gr[i])-a[i];
            if(val>0)
            {
                ans+=val;
            }
        }
        return ans;
    }
};
