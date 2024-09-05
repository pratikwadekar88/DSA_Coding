/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.
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
    // Function to find the intersection node of two singly linked lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // Initialize pointers to traverse both lists
        ListNode *list1 = headA;
        ListNode *list2 = headB;

        // Count the number of nodes in list1
        int cnt1 = 0;
        while (list1) {
            cnt1++;
            list1 = list1->next;
        }

        // Count the number of nodes in list2
        int cnt2 = 0;
        while (list2) {
            cnt2++;
            list2 = list2->next;
        }

        // Calculate the difference in lengths between the two lists
        int diff = cnt1 - cnt2;

        // Adjust headA to align with headB if list1 is longer
        if (cnt1 >= cnt2) {
            diff = cnt1 - cnt2;  // Update the difference in lengths
            while (diff > 0) {
                headA = headA->next;  // Move headA forward by 'diff' nodes
                diff--;
            }
        } 
        // Adjust headB to align with headA if list2 is longer
        else {
            diff = cnt2 - cnt1;  // Update the difference in lengths
            while (diff > 0) {
                headB = headB->next;  // Move headB forward by 'diff' nodes
                diff--;
            }
        }

        // Traverse both lists together to find the intersection point
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        // Return the intersection node (or NULL if no intersection)
        return headA;
    }
};
