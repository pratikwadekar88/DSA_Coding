class LRUCache {
public:

    struct node {
        int key;
        int value;
        node *prev;
        node *next;
        node(int k,int v){
            key = k;
            value = v;
        }
    };


    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);

    int cap ;
    unordered_map<int,node*> mpp;

    void addNode(node* newNode){
        node * temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node* delNode){
        node *temp = delNode;
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mpp.find(key)!=mpp.end()){
            int temp = mpp[key]->value;
            deleteNode(mpp[key]);
            mpp.erase(key);
            node* newNode = new node(key,temp);
            addNode(newNode);
            mpp[key] = newNode;
            return temp;
        }

        return -1;
    }
    
    void put(int key, int value) {
        node * newNode = new node(key,value);
            if(mpp.find(key)!=mpp.end()){
                node* delNode = mpp[key];
                mpp.erase(key);
                deleteNode(delNode);
            }
            if(mpp.size()==cap){
                node *delNode = tail->prev;
                mpp.erase(delNode->key);
                deleteNode(delNode);
            }
            mpp[key]= newNode;
            addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
