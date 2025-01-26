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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL && list2==NULL)
        {
            return list1;
        }
        ListNode* newNode=new ListNode(-1);
        ListNode* head=newNode;
        ListNode* tmp1=list1;
        ListNode* tmp2=list2;
        while(tmp1 !=NULL && tmp2!=NULL)
        {
            if(tmp1->val  < tmp2->val)
            {
                newNode->next=new ListNode(tmp1->val);
                tmp1=tmp1->next;
                newNode=newNode->next;
            }else if(tmp2->val < tmp1 ->val)
            {
                newNode->next=new ListNode(tmp2->val);
                 tmp2=tmp2->next;
                newNode=newNode->next;
            }else if(tmp2->val == tmp1->val) {
                newNode->next=new ListNode(tmp1->val);
                tmp1=tmp1->next;
                newNode=newNode->next;
                 newNode->next=new ListNode(tmp2->val);
                 tmp2=tmp2->next;
                newNode=newNode->next;
            }
        }

        while(tmp1!=NULL)
        {
             newNode->next=new ListNode(tmp1->val);
                tmp1=tmp1->next;
                newNode=newNode->next;
        }

        while(tmp2 !=NULL)
        {
             newNode->next=new ListNode(tmp2->val);
                 tmp2=tmp2->next;
                newNode=newNode->next;
        }
        return head->next;
    
    }
};