
Given a set of reviews provided by the customers for different hotels and a string containing Good Words, 
you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). 
We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

struct Node{
    Node *child[26];
    bool isEnd;
    Node()
    {
        memset(child,0,sizeof(child));
        isEnd=false;
    }
};
void insert(Node *root,string x)
{
    Node *cur=root;
    for(int i=0;i<(x.size());i++)
    {
        int idx=x[i]-'a';
        if(cur->child[idx]==NULL)
        {
            cur->child[idx]=new Node();
        }
        cur=cur->child[idx];
    }
    cur->isEnd=true;
}
bool isPresent(Node *root,string x)
{
    Node *cur=root;
    for(int i=0;i<(x.size());i++)
    {
        int idx=x[i]-'a';
        if(cur->child[idx]==NULL)
        {
            return false;
        }
        cur=cur->child[idx];
    }
    return cur->isEnd;
}
bool mycomp(pair<int, int> a, pair<int, int> b)
{
    if(a.first!=b.first)
    {
        return a.first>b.first;
    }
    return a.second<b.second;
}
vector<int> Solution::solve(string str, vector<string> &vec) {
    string x="";
    Node *root=new Node();
    for(int i=0;i<(str.size());i++)
    {
        if(str[i]!='_')
        {
            x.push_back(str[i]);    
        }else{
            insert(root,x);
            x="";
        }
    }
    insert(root,x);
    x="";
    vector<pair<int,int>> ans;
    for(int i=0;i<(vec.size());i++)
    {
        x=vec[i];
        int cnt=0;
        string check="";
        for(int j=0;j<(x.size());j++)
        {
            if(x[j]!='_')
            {
                check.push_back(x[j]);
            }else{
                if(isPresent(root,check))
                {
                    cnt++;
                }
                check="";
            }
        }
        if(isPresent(root,check))
        {
            cnt++;
        }
        check="";
        ans.push_back({cnt,i});
    }
    sort(ans.begin(),ans.end(),mycomp);
    vector<int> fin;
    for(int i=0;i<(ans.size());i++)
    {
        fin.push_back(ans[i].second);
    }
    return fin;
}


