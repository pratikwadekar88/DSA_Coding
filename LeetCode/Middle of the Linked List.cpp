/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.*/

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
    // Function to find the middle node of a singly linked list
    ListNode* middleNode(ListNode* head) {
        // Base case: if the list is empty or has only one node, return head
        if (head == NULL || head->next == NULL)
            return head;

        // Initialize two pointers: slow moves one step at a time, fast moves two steps
        ListNode *slow = head, *fast = head;

        // Traverse the list until fast pointer reaches the end
        while (fast && fast->next) {
            slow = slow->next;           // Move slow pointer one step
            fast = fast->next->next;     // Move fast pointer two steps
        }

        // At the end of the loop, slow will be at the middle node
        head = slow;
        return head;
    }
};
