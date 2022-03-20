
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

struct Node{
    Node *child[26];
    bool isEnd;
    Node()
    {
        memset(child,0,sizeof(child));
        isEnd=false;
    }
};
class Solution {
public:
    void insert(Node *root,string str)
    {
        Node *cur=root;
        for(int i=0;i<(str.size());i++)
        {
            int idx=str[i]-'a';
            if(!cur->child[idx])
            {
                cur->child[idx]=new Node();
            }
            cur=cur->child[idx];
        }
        cur->isEnd=true;
    }
    
    void func(Node *root,string cur,int idx,int n,bool &ans,string &final_ans,string now)
    {
        if(root->isEnd)
        {
            final_ans=now;
            ans=true;
            return ;
        }
        if(ans)
        {
            return ;
        }
        if(idx==n)
        {
            if(root->isEnd)
            {
                final_ans=now;
                ans=true;
            }
            return ;
        }
        if(root->child[cur[idx]-'a'])
        {
            now.push_back(cur[idx]);
            func(root->child[cur[idx]-'a'],cur,idx+1,n,ans,final_ans,now);
        }else{
            if(root->isEnd)
            {
                final_ans=now;
                ans=true;
            }
            return ;
        }
    }
    string replaceWords(vector<string>& dict, string sent) {
        Node *root=new Node();
        for(int i=0;i<(dict.size());i++)
        {
            insert(root,dict[i]);
        }
        vector<string> vec;
        string temp="";
        for(int i=0;i<(sent.size());i++)
        {
            if(sent[i]!=' ')
            {
                temp.push_back(sent[i]);
            }else{
                vec.push_back(temp);
                temp="";
            }
        }
        vec.push_back(temp);
        string ret="";
        for(int i=0;i<(vec.size());i++)
        {
            string cur=vec[i];
            bool ans=false;
            string final_ans="";
            func(root,cur,0,(cur.size()),ans,final_ans,"");
            if(!final_ans.empty())
            {
                ret=ret+final_ans+" ";
            }else{
                ret=ret+cur+" ";
            }
        }
        ret.pop_back();
        return ret;
    }
};









