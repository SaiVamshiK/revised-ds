class Node{
    public:
        bool isEnd;
        Node *child[26];
        Node(){
            isEnd = false;
            memset(child,0,sizeof(child));
        }
};
class MagicDictionary {
public:
    Node *root;
    MagicDictionary() {
        root = new Node();
    }
    
    void insert(string cur){
        int n = cur.size();
        Node *curNode = root;
        for(int i=0;i<n;i++){
            char ch = cur[i];
            int idx = ch - 'a';
            if(!curNode->child[idx]){
                curNode->child[idx] = new Node();
            }
            curNode = curNode->child[idx];
        }
        curNode->isEnd = true;
    }
    
    void buildDict(vector<string> dictionary) {
        int sz = dictionary.size();
        for(int i=0;i<sz;i++){
            string cur = dictionary[i];
            insert(cur);
        }
    }
    
    bool find(Node *cur,string &str,int idx,int n,bool &changed){
        if(idx == n){
            if(changed){
                return cur->isEnd;
            }
            return false;
        }
        char ch = str[idx];
        int index = ch - 'a';
        if(changed){
            if(cur->child[index]){
                return find(cur->child[index],str,idx+1,n,changed);
            }else{
                return false;
            }
        }else{
            for(int i=0;i<26;i++){
                if(cur->child[i]){
                    if(index == i){
                        bool temp = find(cur->child[i],str,idx+1,n,changed);
                        if(temp){
                            return true;
                        }
                    }else{
                        changed = true;
                        bool temp = find(cur->child[i],str,idx+1,n,changed);
                        if(temp){
                            return true;
                        }
                        changed = false;
                    }
                }
            }
        }
        return false;
    }
    
    bool search(string searchWord) {
        int sz = searchWord.size();
        bool changed = false;
        return find(root,searchWord,0,sz,changed);
    }
};



















/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
