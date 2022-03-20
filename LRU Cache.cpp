Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

struct Node{
    int key,value;
    Node *next,*prev;
    Node(int k,int v)
    {
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    int n;
    Node *head,*tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        n=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        Node *x=mp[key];
        int ans=x->value;
        x->prev->next=x->next;
        x->next->prev=x->prev;
        x->next=NULL;
        x->prev=NULL;
        mp.erase(key);
        Node *insNode=new Node(key,ans);
        Node *temp=head->next;
        head->next=insNode;
        insNode->prev=head;
        temp->prev=insNode;
        insNode->next=temp;
        mp.insert({key,insNode});
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(mp.size()!=n)
            {
                Node *insNode=new Node(key,value);
                Node *temp=head->next;
                head->next=insNode;
                insNode->prev=head;
                temp->prev=insNode;
                insNode->next=temp;
                mp.insert({key,insNode});
            }else{
                Node *x=tail->prev;
                int delKey=x->key;
                x->prev->next=tail;
                x->next->prev=x->prev;
                x->next=NULL;
                x->prev=NULL;
                mp.erase(delKey);
                
                Node *insNode=new Node(key,value);
                Node *temp=head->next;
                head->next=insNode;
                insNode->prev=head;
                temp->prev=insNode;
                insNode->next=temp;
                mp.insert({key,insNode});
                
            }
        }else{
            Node *x=mp[key];
            x->prev->next=x->next;
            x->next->prev=x->prev;
            x->next=NULL;
            x->prev=NULL;
            mp.erase(key);
            
            Node *insNode=new Node(key,value);
            Node *temp=head->next;
            head->next=insNode;
            insNode->prev=head;
            temp->prev=insNode;
            insNode->next=temp;
            mp.insert({key,insNode});
            
        }
    }
};






















