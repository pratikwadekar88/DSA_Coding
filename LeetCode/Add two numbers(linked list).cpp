/* 
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;  // Initialize carry to 0

        // Pointers to traverse the two lists
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        
        // Dummy node to start the resulting linked list
        ListNode *head = new ListNode(-1);
        ListNode *mover = head;  // Pointer to build the new list
        
        // Traverse both lists simultaneously while both nodes are not null
        while (node1 && node2) {
            int sum = node1->val + node2->val + carry;  // Calculate sum of corresponding nodes and carry
            carry = sum / 10;  // Update carry for the next position
            sum = sum % 10;  // Single digit to store in the node

            // Create a new node with the computed sum and attach it to the result list
            ListNode *node = new ListNode(sum);
            mover->next = node;
            mover = mover->next;

            // Move to the next nodes in both lists
            node1 = node1->next;
            node2 = node2->next;
        }

        // If there are remaining nodes in list1, continue processing
        while (node1) {
            int sum = node1->val + carry;  // Add carry to the current node's value
            carry = sum / 10;  // Update carry
            sum = sum % 10;  // Get single digit

            // Create and attach the new node
            ListNode *node = new ListNode(sum);
            mover->next = node;
            mover = mover->next;

            node1 = node1->next;  // Move to the next node in list1
        }

        // If there are remaining nodes in list2, continue processing
        while (node2) {
            int sum = node2->val + carry;  // Add carry to the current node's value
            carry = sum / 10;  // Update carry
            sum = sum % 10;  // Get single digit

            // Create and attach the new node
            ListNode *node = new ListNode(sum);
            mover->next = node;
            mover = mover->next;

            node2 = node2->next;  // Move to the next node in list2
        }

        // If there's a leftover carry, create a new node with it
        if (carry > 0) {
            ListNode *node = new ListNode(carry);
            mover->next = node;
        }

        // Return the head of the new list, skipping the dummy node
        return head->next;
    }
};
