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
    ListNode* Reverse(ListNode* node)
    {
        ListNode* prev=NULL;
        ListNode* curr = node;
        ListNode* nxt = NULL;

        while( curr != NULL)
        {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt ;
        }
        return prev;
    } 
    void reorderList(ListNode* head) {
        
        if(!head || !(head->next) || !(head->next->next) )return ;

        //step  1 find mid point 

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow ->next;
            fast = fast->next->next;
        }

        ListNode* mid =slow->next;
          slow->next = NULL;
        ListNode* lastptr =Reverse(mid);
        ListNode* firstptr = head ;

        while( lastptr )
        {
            ListNode* temp1 = firstptr ->next;
            ListNode* temp2 = lastptr ->next ;

            firstptr->next = lastptr ; 
            lastptr->next =temp1;

            firstptr = temp1;
            lastptr = temp2;

        }

       


    }
};