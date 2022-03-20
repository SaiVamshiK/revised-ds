
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

struct node{
    double valwt;
    double val;
    double wt;
};
bool comparator(node a,node b)
{
    if(a.valwt!=b.valwt)
    {
        return a.valwt>b.valwt;    
    }
    return a.val>b.val;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        node *a=new node[n];
        for(int i=0;i<n;i++)
        {
            a[i].valwt=(double)arr[i].value/(double)arr[i].weight;
            a[i].val=arr[i].value;
            a[i].wt=arr[i].weight;
        }
        sort(a,a+n,comparator);
        double ans=0;
        int idx=0;
        while(idx<n)
        {
            double cur_wt=a[idx].wt;
            if(cur_wt<=W)
            {
                ans+=(a[idx].val);
                W=W-cur_wt;
            }else{
                ans+=(((double)W/cur_wt)*((double)a[idx].val));
                break;
            }
            idx++;
        }
        return ans;
    }
        
};
