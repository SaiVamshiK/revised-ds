
Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.

A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.

 

Example 1:

Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
    
    
struct Node{
    Node *left,*right;
    int leaf_cnt;
    Node()
    {
        left=NULL;right=NULL;
        leaf_cnt=0;
    }
};
class Solution {
public:
    void insert(Node *root,int value)
    {
        Node *cur=root;
        for(int i=31;i>=0;i--)
        {
            int bitVal=(1<<i)&(value);
            if(bitVal==0)
            {
                if(!cur->left)
                {
                    cur->left=new Node();
                }
                cur=cur->left;
            }else{
                if(!cur->right)
                {
                    cur->right=new Node();
                }
                cur=cur->right;
            }
            cur->leaf_cnt++;
        }
    }
    int findCount(Node *root,int curElem,int k)
    {
        Node *cur=root;
        int cnt=0;
        for(int i=31;i>=0;i--)
        {
            int p1=(curElem>>i)&(1);
            int k1=(k>>i)&(1);
            if(p1==1&&(k1==1))
            {
                if(cur->right)
                {
                    cnt+=(cur->right->leaf_cnt);
                }
                if(cur->left)
                {
                    cur=cur->left;
                }else{
                    break;
                }
            }else if(p1==1&&(k1==0))
            {
                if(cur->right)
                {
                    cur=cur->right;
                }else{
                    break;
                }
            }else if(p1==0&&(k1==0))
            {
                if(cur->left)
                {
                    cur=cur->left;
                }else{
                    break;
                }
            }else if(p1==0&&(k1==1))
            {
                if(cur->left)
                {
                    cnt+=(cur->left->leaf_cnt);
                }
                if(cur->right)
                {
                    cur=cur->right;
                }else{
                    break;
                }
            }
        }
        return cnt;
    }
    int countPairsXorLessThanK(vector<int> &a,int n,int k)
    {
        Node *root=new Node();
        int curElem=a[0];
        insert(root,curElem);
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            curElem=a[i];
            cnt+=(findCount(root,curElem,k));
            insert(root,curElem);
        }
        return cnt;
    }
    int countPairs(vector<int>& a, int low, int high) {
        int n=a.size();
        if(n==1||(n==0))
        {
            return 0;
        }
        if(n==2)
        {
            if((a[0]^a[1])<=high&&((a[0]^a[1])>=low))
            {
                return 1;
            }
            return 0;
        }
        return countPairsXorLessThanK(a,n,high+1)-countPairsXorLessThanK(a,n,low);
        
    }
};





struct Node{
    Node *left,*right;
    int leaf_cnt;
    Node()
    {
        left=right=NULL;
        leaf_cnt=0;
    }
};
class Solution {
public:
    void insert(Node *root,int val)
    {
        Node *cur=root;
        cur->leaf_cnt++;
        for(int i=31;i>=0;i--)
        {
            int temp=((1<<i)&val);
            if(temp==0)
            {
                if(!cur->left)
                {
                    cur->left=new Node();
                }
                cur=cur->left;
                cur->leaf_cnt++;
            }else{
                if(!cur->right)
                {
                    cur->right=new Node();
                }
                cur=cur->right;
                cur->leaf_cnt++;
            }
        }
    }
    void func(Node *root,int val,int limit,int &ans)
    {
        Node *cur=root;
        for(int i=31;i>=0;i--)
        {
            int cur1=((val>>i)&1);
            int cur2=((limit>>i)&1);
            if((cur1==1)&&(cur2==1))
            {
                if(cur->right)
                {
                    ans+=(cur->right->leaf_cnt);
                }
                if(cur->left)
                {
                    cur=cur->left;
                }else{
                    break;
                }
            }else if((cur1==1)&&(cur2==0))
            {
                if(cur->right)
                {
                    cur=cur->right;
                }else{
                    break;
                }
            }else if((cur1==0)&&(cur2==0))
            {
                if(cur->left)
                {
                    cur=cur->left;
                }else{
                    break;
                }
            }else if((cur1==0)&&(cur2==1))
            {
                if(cur->left)
                {
                    ans+=(cur->left->leaf_cnt);
                }
                if(cur->right)
                {
                    cur=cur->right;
                }else
                {
                    break;
                }
            }
        }
    }
    int countPairs(vector<int>& a, int l, int h) {
        int n=a.size();
        Node *root=new Node();
        for(int i=0;i<n;i++)
        {
            insert(root,a[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int elem=a[i];
            int right=0,left=0;
            func(root,elem,h+1,right);
            func(root,elem,l,left);
            ans+=((right-left));
        }
        return ans/2;
    }
};
