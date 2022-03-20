class NumArray {
public:
    int *bit;
    int *a;
    int n;
    void ins(int i,int val)
    {
        for(;i<=n;i+=(i&(-i)))
        {
            bit[i]+=val;
        }
    }
    int query(int i)
    {
        int sum=0;
        for(;i>0;i-=(i&(-i)))
        {
            sum+=bit[i];
        }
        return sum;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        a=new int[n+1];
        bit=new int[n+1];
        for(int i=0;i<n;i++)
        {
            a[i+1]=nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            bit[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            ins(i,a[i]);
        }
    }
    
    void update(int index, int val) {
        index++;
        int prev=query(index)-query(index-1);
        ins(index,val-prev);
    }
    
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
    }
};
















/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
