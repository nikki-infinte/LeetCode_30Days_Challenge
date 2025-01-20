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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Handle edge cases
        
        ListNode* odd = head;            // Start of the odd list
        ListNode* even = head->next;     // Start of the even list
        ListNode* evenHead = even;       // To link at the end of the odd list
        
        while (even && even->next) {
            odd->next = even->next;      // Link current odd node to the next odd node
            odd = odd->next;             // Move odd pointer to the next odd node
            
            even->next = odd->next;      // Link current even node to the next even node
            even = even->next;           // Move even pointer to the next even node
        }
        
        odd->next = evenHead;            // Concatenate the odd and even lists
        return head;
    }
};
