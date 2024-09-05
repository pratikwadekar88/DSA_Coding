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

    // Function to reverse a linked list and return the new head
    ListNode* reverse(ListNode* head) {
        // Base case: if the list is empty or contains only one node, return the head
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverse(head->next);

        // Reverse the pointers between the current node and the next node
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL; // Set the current node's next to NULL (it becomes the new tail)
        
        return newHead; // Return the new head of the reversed list
    }

    // Approach 2:
    // This approach takes O(n) time complexity and O(1) space complexity
    bool isPalindrome(ListNode* head) {
        // If the list has only one node, it's trivially a palindrome
        if (head->next == NULL)
            return true;

        int cnt = 0;  // Counter to count the number of nodes
        ListNode* mover = head;  // Temporary pointer to traverse the list

        // Traverse the list to count the number of nodes
        while (mover) {
            mover = mover->next;
            cnt++;
        }

        ListNode* slow = head;  // Slow pointer (moves one step at a time)
        ListNode* fast = head;  // Fast pointer (moves two steps at a time)
        ListNode* temp = NULL;  // Pointer to store the node just before the middle of the list

        // Find the middle of the list using the slow and fast pointer approach
        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has an even number of nodes, fast will stop at the middle node
        if (cnt % 2 == 0)
            fast = slow;
        else
            fast = slow->next; // If the list has an odd number of nodes, skip the middle node

        temp->next = NULL;  // Split the list into two halves

        // Reverse the first half of the list
        slow = reverse(head);

        // Compare the two halves of the list
        while (slow && fast) {
            if (slow->val != fast->val)  // If the values don't match, it's not a palindrome
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        // Check if both halves are exhausted or if only one extra node remains
        if ((slow == NULL && fast == NULL))
            return true;  // It's a palindrome

        return false;  // Not a palindrome
    }

    // Approach 1:
    // This solution requires O(n) time complexity and O(n) space.
    /*
    bool isPalindrome(ListNode* head) {
        // Reverse the entire list
        ListNode* head2 = reverse(head);

        // Compare the original list with the reversed list
        while (head && head2) {
            if (head->val != head2->val)  // If values don't match, it's not a palindrome
                return false;
            head = head->next;
            head2 = head2->next;
        }

        return true;  // It's a palindrome
    }
    */
};
