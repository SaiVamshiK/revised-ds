The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"

class Solution {
public:
    void func(string &inp,string &op,bool *visited,int n,int &k,string &ans,bool &done)
    {
        if(op.size()==n)
        {
            k--;
            if(k==0)
            {
                ans=op;
                done=true;
            }
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                op.push_back(inp[i]);
                func(inp,op,visited,n,k,ans,done);
                visited[i]=false;
                op.pop_back();
                if(done)
                {
                    return ;
                }
            }
        }
    }
    string getPermutation(int n, int k) {
        string inp="",op="";
        for(int i=1;i<=n;i++)
        {
            inp+=to_string(i);
        }
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        string ans="";
        bool done=false;
        func(inp,op,visited,n,k,ans,done);
        return ans;
    }
};
