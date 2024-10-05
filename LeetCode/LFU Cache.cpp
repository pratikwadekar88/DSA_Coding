struct node{
    int key;        // Key associated with this node (represents a cache item)
    int value;      // Value associated with the key (cache item data)
    int cnt ;       // Frequency count of accesses (for LFU)
    node* prev;     // Pointer to previous node in the list (doubly linked list)
    node* next;     // Pointer to next node in the list (doubly linked list)

    // Constructor to initialize a node with key and value, and set frequency count to 1
    node(int k,int v){
        key = k;
        value = v;
        cnt = 1;    // Initial frequency of any node is 1 (first access)
    }
};

struct List {
    int size;       // Number of nodes currently in the list
    node *head ;    // Dummy head node for easy list manipulation
    node *tail;     // Dummy tail node for easy list manipulation

    // Constructor to initialize an empty list with dummy head and tail
    List(){
        head = new node(0,0);    // Dummy node with key 0, value 0
        tail = new node(0,0);    // Dummy node with key 0, value 0
        head->next = tail;       // Head's next points to tail
        tail->prev = head;       // Tail's prev points to head
        size = 0;                // Initially the list is empty
    }
    
    // Function to add a node right after the head (most recently used position)
    void addNode(node* newnode){
        node *temp = head->next; // Temporary node to store the node after the head
        newnode->next = temp;    // Set new node's next to head's next (temp)
        newnode->prev = head;    // Set new node's prev to head
        head->next = newnode;    // Update head's next to point to the new node
        temp->prev = newnode;    // Update temp's previous to point to the new node
        size++;                  // Increase the size of the list
    }

    // Function to remove a node from the list
    void removeNode(node* delNode){
        node* temp = delNode;            // Temporary node to hold the node to be deleted
        delNode->prev->next = delNode->next;  // Update the previous node's next to skip delNode
        delNode->next->prev = delNode->prev;  // Update the next node's prev to skip delNode
        size--;                           // Decrease the size of the list
    }
};

class LFUCache {
public:

    unordered_map<int, List*> freqMap; // Maps frequency to the corresponding doubly linked list
    unordered_map<int, node*> keyMap;  // Maps key to its node in the cache

    int minfreq;   // Tracks the minimum frequency of any node in the cache
    int maxCache;  // Maximum capacity of the cache
    int curSize;   // Current number of elements in the cache

    // Constructor to initialize the LFU Cache with a given capacity
    LFUCache(int capacity) {
        maxCache = capacity;   // Set maximum cache size
        minfreq = 0;           // Initially, no nodes have been accessed
        curSize = 0;           // Cache starts empty
    }
    
    // Function to update the frequency of a node in the cache
    void updateFreqListMap(node* node){
        keyMap.erase(node->key);               // Remove node from keyMap
        freqMap[node->cnt]->removeNode(node);  // Remove node from its current frequency list

        // If the current node's frequency is the minimum and its list is empty, increase minfreq
        if(node->cnt == minfreq && freqMap[node->cnt]->size == 0){
            minfreq++;
        }

        // Prepare to add the node to the next higher frequency list
        List* nextHigherFreq = new List();
        if(freqMap.find(node->cnt + 1) != freqMap.end()){
            nextHigherFreq = freqMap[node->cnt + 1];
        }

        node->cnt += 1;                    // Increment the node's frequency
        nextHigherFreq->addNode(node);     // Add node to the list with the next higher frequency
        freqMap[node->cnt] = nextHigherFreq; // Update frequency map
        keyMap[node->key] = node;          // Add node back to keyMap with updated frequency
    }

    // Function to get the value of a key from the cache
    int get(int key) {
        if(keyMap.find(key) != keyMap.end()){  // If the key is present in the cache
            node* getnode = keyMap[key];       // Get the node
            int val = getnode->value;          // Get its value
            updateFreqListMap(getnode);        // Update its frequency
            return val;                        // Return the value
        }
        return -1;  // Return -1 if key is not found in the cache
    }
    
    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        if(maxCache == 0){  // If cache capacity is 0, do nothing
            return ;
        }

        if(keyMap.find(key) != keyMap.end()){  // If the key already exists in the cache
            node* node = keyMap[key];          // Get the existing node
            node->value = value;               // Update its value
            updateFreqListMap(node);           // Update its frequency
        } else {
            // If the cache is full, remove the least frequently used node
            if(curSize == maxCache){ 
                List *list = freqMap[minfreq];              // Get the least frequent list
                keyMap.erase(list->tail->prev->key);        // Remove the least frequent node from keyMap
                freqMap[minfreq]->removeNode(list->tail->prev);  // Remove it from the list
                curSize--;                                  // Decrease the current size
            }
            curSize++;  // Increase current size for new node
            minfreq = 1;  // Reset minimum frequency to 1 for the new node

            // Find or create a new list for frequency 1
            List *newlist = new List();
            if(freqMap.find(minfreq) != freqMap.end()){
                newlist = freqMap[minfreq];
            }

            // Create a new node and add it to the frequency list
            node* newnode = new node(key, value);
            newlist->addNode(newnode);   
            keyMap[key] = newnode;    // Add new node to keyMap
            freqMap[minfreq] = newlist;  // Update frequency map for freq 1
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
