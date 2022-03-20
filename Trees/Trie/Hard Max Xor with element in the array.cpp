You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]

struct Node{
    int xi,mi;
    int idx,ans;
};  
bool comparator(Node a,Node b)
{
    return a.mi<b.mi;
}
struct TrieNode{
    TrieNode *left,*right;
    TrieNode()
    {
        left=right=NULL;
    }
};
class Solution {
public:
    void insert(TrieNode *root,int val)
    {
        TrieNode *cur=root;
        for(int i=31;i>=0;i--)
        {
            int temp=((1<<i)&val);
            if(temp==0)
            {
                if(!cur->left)
                {
                    cur->left=new TrieNode();
                }
                cur=cur->left;
            }else{
                if(!cur->right)
                {
                    cur->right=new TrieNode();
                }
                cur=cur->right;
            }
        }
    }
    int query(TrieNode *root,int val)
    {
        TrieNode *cur=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int temp=((1<<i)&val);
            if(temp==0)
            {
                if(cur->right)
                {
                    ans+=(pow(2,i));
                    cur=cur->right;
                }else{
                    cur=cur->left;
                }
            }else{
                if(cur->left)
                {
                    ans+=(pow(2,i));
                    cur=cur->left;
                }else{
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode *root=new TrieNode();
        int q=queries.size();
        Node *arr=new Node[q];
        for(int i=0;i<q;i++)
        {
            arr[i].xi=queries[i][0];
            arr[i].mi=queries[i][1];
            arr[i].idx=i;
            arr[i].ans=-1;
        }
        sort(arr,arr+q,comparator);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int idx=0;
        for(int i=0;i<q;i++)
        {
            int val_mi=arr[i].mi;
            while(idx<n&&(nums[idx]<=val_mi))
            {
                insert(root,nums[idx]);
                idx++;
            }
            if(idx==0)
            {
                arr[i].ans=-1;
            }else{
                int tmp=query(root,arr[i].xi);
                arr[i].ans=tmp;
            }
        }
        vector<int> fin(q,-1);
        for(int i=0;i<q;i++)
        {
            fin[arr[i].idx]=arr[i].ans;
        }
        return fin;
    }
};
