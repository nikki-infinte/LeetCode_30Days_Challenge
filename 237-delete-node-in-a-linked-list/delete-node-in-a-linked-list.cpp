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
    void deleteNode(ListNode* node) {
        
        ListNode* tmp = node;
        ListNode* prev =NULL;
        while(tmp->next!=NULL)
        {
            prev = tmp;
            tmp->val= tmp->next->val;
            tmp = tmp->next;
        }
        if(tmp->next == NULL){
            prev->next =NULL;
            delete(tmp);
        }
        
    }
};