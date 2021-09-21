
struct Node
{
    int key,value;
    Node *left,*right;
    Node():key(0),value(0),left(nullptr),right(nullptr){}
    Node(int k, int v):key(k),value(v),left(nullptr),right(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node *L;
    Node *R;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        L = new Node();
        R = new Node();
        L->right = R;
        R->left = L;

    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        else{
            auto p = cache[key];
            remove(p);
            insert(p);
            return p->value;
        }
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            Node *element = new Node(key, value);
            cache[key] = element;
            auto p = cache[key];
            size++;
            insert(p);
            if(size>capacity){
                auto p = cache[R->left];
                remove(p);
                cache.erase(p->key);
                delete p;
            }
        }
        else{
            auto p = cache[key];
            p->value = value;
            remove(p);
            insert(p);
        }
    }

    void remove(Node *p){
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert(Node *p){
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */