struct Node{
    unordered_map<char,Node*> mp;
    bool isEnd;
    Node()
    {
        isEnd=false;
    }
};
class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        Node *cur=root;
        for(int i=0;i<(s.size());i++)
        {
            if(cur->mp[s[i]]==NULL)
            {
                cur->mp[s[i]]=new Node();
            }
            cur=cur->mp[s[i]];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        Node *cur=root;
        for(int i=0;i<(s.size());i++)
        {
            if(cur->mp[s[i]]==NULL)
            {
                return false;
            }
            cur=cur->mp[s[i]];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        Node *cur=root;
        for(int i=0;i<(s.size());i++)
        {
            if(cur->mp[s[i]]==NULL)
            {
                return false;
            }
            cur=cur->mp[s[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
