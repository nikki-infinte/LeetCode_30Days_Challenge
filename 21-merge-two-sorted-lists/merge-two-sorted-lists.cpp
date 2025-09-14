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
        
        ListNode* newNodeHead = new ListNode(-1);
        ListNode* newNode = newNodeHead;
        ListNode* tmp = list1;
        ListNode* tmp2 = list2;

        while(tmp && tmp2){


            if(tmp->val == tmp2->val){
                newNode->next = new ListNode(tmp->val);
                newNode = newNode->next;
                newNode->next = new ListNode(tmp2->val);

                tmp=tmp->next;
                tmp2 = tmp2->next;
            }else if(tmp->val < tmp2->val){


                newNode->next = new ListNode(tmp->val);
                tmp=tmp->next;
                
            }else{
                newNode->next = new ListNode(tmp2->val);
                tmp2=tmp2->next;
               
            }
             newNode = newNode->next;
        }

        while(tmp){
            newNode->next = new ListNode(tmp->val);
            tmp=tmp->next;
            newNode = newNode->next;
        }

        while(tmp2){
            newNode->next = new ListNode(tmp2->val);
            tmp2 = tmp2->next;
            newNode = newNode->next;
        }
        return newNodeHead->next;
    }
};