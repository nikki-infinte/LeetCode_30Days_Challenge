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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)return head;
        
        ListNode* slow =head;
        ListNode* fast =head->next;
        ListNode* prev=NULL;
        ListNode* currHead =head->next;
        while(slow != NULL && fast != NULL)
        {
            slow->next =fast->next;
            fast->next = slow;

            //connect prev node
            if(prev!=NULL)
            {
                prev ->next =fast;
            }
            prev = slow;
            slow=slow->next;
           if (slow != NULL) {
                fast = slow->next;
            } else {
                fast = NULL;
            }
        }
        return currHead;

    }
};