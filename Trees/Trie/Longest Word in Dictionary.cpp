
Given a list of strings words representing an English Dictionary, 
find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

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
    void func(Node *root,string &ans,bool &done,int now,string &final_ans)
    {
        if(root->isEnd||(now==0))
        {
            for(int i=0;i<26;i++)
            {
                if(root->child[i]&&(root->child[i]->isEnd))
                {
                    ans.push_back('a'+i);
                    if(ans.size()>(final_ans.size()))
                    {
                        final_ans=ans;
                    }
                    func(root->child[i],ans,done,1,final_ans);
                    ans.pop_back();
                }
            }    
        }
        
    }
    string longestWord(vector<string>& vec) {
        int n=vec.size();
        Node *root=new Node();
        for(int i=0;i<n;i++)
        {
            insert(root,vec[i]);
        }
        string ans="";
        bool done=false;
        string final_ans="";
        func(root,ans,done,0,final_ans);
        return final_ans;
    }
};










