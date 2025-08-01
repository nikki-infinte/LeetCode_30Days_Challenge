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
    ListNode* deleteDuplicates(ListNode* head) {
        
      if(head == nullptr || head->next == nullptr) return head;

       // ListNode* pre = nullptr;
        ListNode* tmp = head;
        while(tmp->next != nullptr){

            if(tmp!=nullptr &&  tmp->next != nullptr && tmp->val == tmp->next->val)
            {
                tmp->next = tmp->next->next;
            }else{
                    tmp = tmp->next;
            }
        
        }
        return head;

    }
};