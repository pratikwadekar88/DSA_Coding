/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

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
    // Function to merge two sorted singly linked lists into one sorted list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Create a dummy node to serve as the starting point for the merged list
        ListNode* node = new ListNode(-1);
        
        // Pointer to track the current end of the merged list
        ListNode* head = node;

        // Loop until one of the lists becomes empty
        while (list1 && list2) {
            // Compare the current nodes of both lists and link the smaller one
            if (list1->val <= list2->val) {
                node->next = list1;  // Link list1's node to the merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                node->next = list2;  // Link list2's node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            node = node->next; // Move the merged list pointer forward
        }

        // If there are remaining nodes in list1, link them to the merged list
        while (list1) {
            node->next = list1;
            list1 = list1->next;
            node= node->next;
        }

        // If there are remaining nodes in list2, link them to the merged list
        while (list2) {
            node->next = list2;
            list2 = list2->next;
            node= node->next;
        }

        // Return the next node after the dummy node, which is the actual head of the merged list
        return head->next;
    }
};
