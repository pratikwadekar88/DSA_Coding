/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    // Function to detect if a cycle exists in the linked list and return the starting node of the cycle
    ListNode *detectCycle(ListNode *head) {
        // Edge case: if the list is empty or contains only one node, no cycle can exist
        if (head == NULL || head->next == NULL)
            return NULL;

        // Initialize two pointers, slow and fast, both starting at the head
        ListNode* slow = head;
        ListNode* fast = head;

        // Move the pointers: slow moves one step, fast moves two steps
        if (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Traverse the list with slow and fast pointers
        // If there's a cycle, slow and fast will eventually meet
        while (fast && fast->next && slow != fast) {
            slow = slow->next;         // Slow pointer moves one step
            fast = fast->next->next;   // Fast pointer moves two steps
        }

        // If fast pointer reaches the end (no cycle), return NULL
        if (fast == NULL || fast->next == NULL)
            return NULL;

        // Reset the slow pointer to the head, and move both pointers one step at a time
        slow = head;

        // When slow and fast meet again, they will meet at the start of the cycle
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // If slow and fast pointers meet, return the node where the cycle starts
        if (slow == fast)
            return fast;

        // If no cycle exists, return NULL (although this condition is unlikely to be reached)
        return NULL;
    }
};
