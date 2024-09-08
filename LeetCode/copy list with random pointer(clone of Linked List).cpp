/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.*/

/*
// Definition for a Node.
class Node {
public:
    int val;           // Value of the node
    Node* next;        // Pointer to the next node
    Node* random;      // Pointer to any random node (or nullptr)
    
    Node(int _val) {   // Constructor to initialize the node
        val = _val;
        next = NULL;   // Initialize next as nullptr
        random = NULL; // Initialize random as nullptr
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Approach 2 : Without using extra space

        Node* temp = head;
        
        // Step 1: Clone each node and place the clone next to the original node
        while(temp) {
            Node* node = new Node(temp->val);  // Create a new node with the same value
            node->next = temp->next;           // Link new node's next to the original node's next
            temp->next = node;                 // Insert the new node just after the current node
            temp = temp->next->next;           // Move to the next original node
        }

        temp = head;
        
        // Step 2: Assign random pointers for the copied nodes
        while(temp) {
            Node* copynode = temp->next;       // Access the newly created node
            if(temp->random)                   // If original node has a random pointer
                copynode->random = temp->random->next; // Assign random pointer to cloned node
            else
                copynode->random = nullptr;    // If no random pointer, set nullptr

            temp = temp->next->next;           // Move to the next original node
        }

        temp = head;    
        Node* dummyNode = new Node(-1);        // Dummy node to store the copied list
        Node *res = dummyNode;                 // Pointer to traverse the copied list
        
        // Step 3: Separate the copied list from the original list
        while(temp) {
            res->next = temp->next;            // Append copied node to the result list
            res = res->next;                   // Move to the next node in the copied list

            temp->next = temp->next->next;     // Restore the original list by linking original nodes
            temp = temp->next;                 // Move to the next original node
        }

        return dummyNode->next;                // Return the head of the copied list

        // Approach 1: Using O(n) extra space (commented out)
        // unordered_map<Node*, Node*> mpp;
        //
        // Node* temp = head;
        // 
        // while(temp) {
        //     Node* node = new Node(temp->val); // Create a new node for each original node
        //     mpp[temp] = node;                 // Map original node to its copy
        //     temp = temp->next;
        // }
        //
        // temp = head;
        // while(temp) {
        //     mpp[temp]->next = mpp[temp->next];   // Link copied nodes' next pointers
        //     mpp[temp]->random = mpp[temp->random]; // Link copied nodes' random pointers
        //     temp = temp->next;
        // }
        // return mpp[head];   // Return the copied list
    }
};
