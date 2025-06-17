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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1 = headA;
        ListNode* tmp2 =headB;

        if(tmp1 == nullptr || tmp2 == nullptr)return nullptr;

        while(tmp1!=tmp2)
        {
            if(tmp1!=NULL)tmp1=tmp1->next;
            else if(tmp1==NULL)tmp1= headA;

            if(tmp2!=NULL)tmp2=tmp2->next;
            else if(tmp2==NULL)tmp2= headB;

        }
        return tmp1;

    }
};