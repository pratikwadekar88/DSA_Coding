class Solution {
public:
    Node* connect(Node* root) {
        // Base case: if the root is NULL, return NULL (no tree to connect)
        if (root == NULL)
            return root;

        // Initialize a queue for level-order traversal
        queue<Node*> q;
        q.push(root);

        // Perform level-order traversal using a queue
        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level

            // Iterate through all nodes at the current level
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); // Get the front node from the queue
                q.pop();

                // Link the current node's 'next' pointer to the next node in the queue,
                // except for the last node at each level
                if (i != size - 1)
                    node->next = q.front();

                // Add the left child to the queue if it exists
                if (node->left)
                    q.push(node->left);

                // Add the right child to the queue if it exists
                if (node->right)
                    q.push(node->right);
            }
        }

        // Return the root after connecting all 'next' pointers
        return root;
    }
};
