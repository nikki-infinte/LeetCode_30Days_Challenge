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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        //have to increment slow by one and fast by 2
        //odd length-->while(fast->nxt !=null)
        //even length-->while(fast!=NULL)
        int count=0;
        ListNode* tmp=head;
        while(tmp->next!=NULL)
        {
            count++;
            tmp=tmp->next;
        }
        // Move slow by one step and fast by two steps until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }


};