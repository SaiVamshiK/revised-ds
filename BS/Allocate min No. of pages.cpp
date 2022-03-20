
class Solution 
{
    public:
    
    bool isPossible(int a[],int n,int m,int maxPages)
    {
        if(m>n)
        {
            return false;
        }
        int curPages=0,cnt=1;
        for(int i=0;i<n;i++)
        {
            curPages+=a[i];
            if(curPages>maxPages)
            {
                cnt++;
                curPages=a[i];
            }
        }
        return cnt<=m;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        int start=INT_MIN,end=0;
        for(int i=0;i<n;i++)
        {
            start=max(start,a[i]);
            end+=a[i];
        }
        int ans=-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isPossible(a,n,m,mid))
            {
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};


class Solution {
  public:
    bool isValid(int minPages,int a[],int n,int m)
    {
        int count=1;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if((cur+a[i])<=minPages)
            {
                cur=cur+a[i];
            }else{
                count++;
                cur=0;
                if((cur+a[i])<=minPages)
                {
                    cur=cur+a[i];
                }else{
                    return false;
                }
            }
            if(count>m)
            {
                return false;
            }
        }
        return true;
    }
    int findPages(int a[], int n, int m) {
        if(n<m)
        {
            return -1;
        }
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            end+=a[i];
        }
        int ans=-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(isValid(mid,a,n,m))
            {
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};



