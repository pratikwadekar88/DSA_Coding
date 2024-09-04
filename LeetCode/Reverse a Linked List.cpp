/* 
 * Given the head of a singly linked list, reverse the list, 
 * and return the reversed list.
 */

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

    // Function to reverse a singly linked list
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one node, return head
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse the current node by pointing the next node back to this node
        ListNode* front = head->next;
        front->next = head;

        // Disconnect the current node from the rest of the list
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};
