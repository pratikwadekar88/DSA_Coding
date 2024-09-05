/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to reverse a linked list starting from the given head node
    void reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one node, nothing to reverse
        if(head == NULL || head->next == NULL)
            return;

        // Recursively reverse the rest of the list
        reverseList(head->next);

        // Adjust pointers to reverse the current pair of nodes
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL; // Set the current node's next to NULL (it will be the new tail)
    }

    // Function to get the kth node from the current node
    ListNode* getkthNode(ListNode* node, int k) {
        k -= 1; // Decrement k as we are starting from the current node
        // Traverse the list until we reach the kth node or the end
        while (node && k > 0) {
            node = node->next;
            k--;
        }
        return node; // Return the kth node (or NULL if k exceeds the list length)
    }

    // Function to reverse nodes in k groups in the linked list
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;      // Pointer to traverse the list
        ListNode* prevNode = NULL;  // Pointer to the node just before the current group
        ListNode* nextNode = NULL;  // Pointer to the node just after the current group

        while (1) {
            // Get the kth node from the current position
            ListNode* kthNode = getkthNode(temp, k);
            // If the kth node is NULL, there are fewer than k nodes left, so stop reversing
            if (kthNode == NULL) {
                if (prevNode) {
                    prevNode->next = temp; // Connect the last part of the list
                }
                break; // Exit the loop as no more full groups remain
            }

            // Save the next node after the kth node
            nextNode = kthNode->next;
            kthNode->next = NULL; // Temporarily disconnect the group from the rest of the list

            // Reverse the current group of k nodes
            reverseList(temp);

            // If reversing the first group, update the head of the list
            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode; // Connect the previously reversed part with the current group
            }

            // Move prevNode to the last node of the current group (temp was the head before reversing)
            prevNode = temp;
            // Move temp to the next node to start reversing the next group
            temp = nextNode;
        }

        return head; // Return the new head of the list after all reversals
    }
};
