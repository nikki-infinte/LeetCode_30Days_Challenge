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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>vec;
        ListNode* tmp = head->next; // Skip the first node which is always zero
        int x = 0;

        // Traverse the list and accumulate values between zeros
        while (tmp != nullptr) {
            if (tmp->val != 0) {
                x += tmp->val;
            } else {
                vec.push_back(x);
                x = 0;
            }
            tmp = tmp->next;
        }

        ListNode* dummy = new ListNode(0); // Dummy node to simplify list creation
        ListNode* current = dummy;
        for (int val : vec) {
            current->next = new ListNode(val);
            current = current->next;
        }

        return dummy->next;
    }
};