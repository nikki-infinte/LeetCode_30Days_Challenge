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


    void deleteWithoutHead(ListNode* node)
    {
        ListNode* tmp = node->next;
        if(tmp!=NULL)
        {
            node->val = tmp->val;
            node->next = tmp->next;
            delete tmp;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

       if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i=0;i<=n;i++)fast = fast ->next;

        while(fast!=NULL)
        {
            slow = slow ->next;
            fast = fast->next;

        }
       if (slow->next && slow->next->next) {
            deleteWithoutHead(slow->next);
        }else{
            ListNode* tmp = slow->next;
            slow->next = slow->next->next;
            delete tmp;
        }
          ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};