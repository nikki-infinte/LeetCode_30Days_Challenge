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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftList =new ListNode(-1);
        ListNode* rightList = new ListNode(-1);
        ListNode* tmp = head;

    ListNode* leftptr=leftList;
    ListNode* rightptr = rightList;

        while(tmp!=nullptr)
        {
            if(tmp->val < x){
                leftptr->next = new ListNode(tmp->val);
                leftptr=leftptr->next;
               
            }
            if(tmp->val >= x)
            {
                rightptr->next =  new ListNode(tmp->val);
                rightptr=rightptr->next;
            }
            tmp=tmp->next;
        }
        //leftptr->next = new ListNode(x);
        // leftptr = leftptr->next;
        leftptr->next =rightList->next;
        return leftList->next;

    }
};