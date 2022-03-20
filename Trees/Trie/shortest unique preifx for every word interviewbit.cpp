/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov


*/

struct Node{
    Node *child[26];
    bool isEnd;
    int leaf_cnt;
    Node()
    {
        memset(child,0,sizeof(child));
        isEnd=false;
        leaf_cnt=0;
    }
};
void insert(string s,Node *root)
{
    Node *cur=root;
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        if(!cur->child[idx])
        {
            cur->child[idx]=new Node();
        }
        cur=cur->child[idx];
        cur->leaf_cnt++;
    }
    cur->isEnd=true;
}
string find(string s,Node *root)
{
    Node *cur=root;
    string ret="";
    for(int i=0;i<(s.size());i++)
    {
        int idx=s[i]-'a';
        cur=cur->child[idx];
        ret.push_back(s[i]);
        if(cur->leaf_cnt==1)
        {
            break;
        }
    }
    return ret;
}
vector<string> Solution::prefix(vector<string> &A) {
    int n=A.size();
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        insert(A[i],root);
    }
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        string t=find(A[i],root);
        ans.push_back(t);
    }
    return ans;
}






