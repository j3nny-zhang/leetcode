// Given head, the head of a linked list, determine if the linked list has a cycle in it.


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
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;

        while(p2 && p2->next) {
        
            p2 = p2->next->next;
            if (p1 == p2) return true;

            p1 = p1->next;
        }

        return false;
    }
};
