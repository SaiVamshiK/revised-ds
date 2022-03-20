void search1(const vector<int> &A,int n,int val,int &first)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(A[mid]<val)
        {
            start=mid+1;
        }else if(A[mid]>val)
        {
            end=mid-1;
        }else{
            first=mid;
            end=mid-1;
        }
    }
}
void search2(const vector<int> &A,int n,int val,int &first)
{    
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(A[mid]<val)
        {
            start=mid+1;
        }else if(A[mid]>val)
        {
            end=mid-1;
        }else{
            first=mid;
            start=mid+1;
        }
    }
}
vector<int> Solution::searchRange(const vector<int> &A, int val) {
    vector<int> ans(2,-1);
    int n=A.size();
    int first=-1;
    search1(A,n,val,first);
    if(first==-1)
    {
        return ans;
    }
    ans[0]=first;
    search2(A,n,val,ans[1]);
    return ans;
}

