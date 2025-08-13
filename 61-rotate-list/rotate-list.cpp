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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)return nullptr;

        int size =0;
        ListNode* tmp = head;
        
        while(tmp!=nullptr){
            size++;
            tmp=tmp->next;
        }

        k = k % size;
        if(k ==0 )return head;

        
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0;i<k;i++){
            fast = fast->next;
        }

        while(fast->next){
            slow = slow ->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
        
    }
};