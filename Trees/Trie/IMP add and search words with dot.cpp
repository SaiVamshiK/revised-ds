struct Node{
    Node *child[26];
    bool isEnd;
    Node()
    {
        isEnd=false;
        memset(child,0,sizeof(child));
    }
};
class WordDictionary {
public:
    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string s) {
        Node *cur=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int idx=s[i]-'a';
            if(!cur->child[idx])
            {
                cur->child[idx]=new Node();
            }
            cur=cur->child[idx];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool solve(Node *root,string s,int start,int n)
    {
        Node *cur=root;
        for(int i=start;i<n;i++)
        {
            int idx=s[i]-'a';
            if(s[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(cur->child[j])
                    {
                        bool temp=solve(cur->child[j],s,i+1,n);
                        if(temp)
                        {
                            return temp;
                        }
                    }
                }
                return false;
            }else{
                if(!cur->child[idx])
                {
                    return false;
                }
                cur=cur->child[idx];
            }
        }
        return cur->isEnd;
    }
    bool search(string s) {
        int i=0,n=s.size();
        return solve(root,s,i,n);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */










