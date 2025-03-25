class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle empty list or single node or zero rotation
        if (!head || !head->next || k == 0) return head;
        
        // Calculate correct list length
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next) {
            len++;
            tmp = tmp->next;
        }
        
       
        k = k % len;
        if (k == 0) return head;
        
       
        ListNode* newTail = head;
        for(int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }
        
       
        ListNode* newHead = newTail->next;
        
        // Connect the last node to original head
        tmp->next = head;
        
        // Break the list at new tail
        newTail->next = nullptr;
        
        return newHead;
    }
};