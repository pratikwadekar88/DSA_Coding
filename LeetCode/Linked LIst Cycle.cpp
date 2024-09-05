/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Function to detect if a linked list has a cycle
    bool hasCycle(ListNode *head) {
        
        // Approach 1: Using a set to store nodes and check for duplicates (O(n) space)
        // Approach 2: Tortoise and hare method (Floyd's Cycle Detection Algorithm)

        // If the list is empty or has only one node, there is no cycle
        if (!head || !head->next)
            return false;

        // Initialize two pointers, slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the pointers to start their traversal
        if (fast && fast->next) {
            slow = slow->next;            // Slow moves one step
            fast = fast->next->next;      // Fast moves two steps
        }

        // Traverse the list with slow moving one step and fast moving two steps
        // If they meet, a cycle is detected
        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If slow and fast pointers meet, there is a cycle
        while (slow && fast && slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Return true if cycle detected, false otherwise
        if (slow == fast)
            return true;

        return false;  // No cycle detected
    }
};
