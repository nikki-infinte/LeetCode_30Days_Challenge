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

    ListNode* MiddleNode(ListNode* head)
    {
        ListNode*slow,*fast ;
        slow =head;
        fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* node1,ListNode* node2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(node1!=nullptr && node2 != nullptr){
            if(node1->val < node2->val){
                temp->next = node1;
               
                node1=node1->next;
            }else {
                temp->next = node2;
                node2=node2->next;
            }
             temp=temp->next;
        }

      if(node1 != nullptr) temp->next = node1;
        else temp->next = node2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {

        if(head == nullptr || head->next ==nullptr )return head;
        ListNode* middle= MiddleNode(head);
        ListNode* leftNode = head;
        ListNode* rightNode = middle->next;

        middle->next = nullptr;
        leftNode = sortList(leftNode);
        rightNode =sortList(rightNode);
        return mergeTwoLists(leftNode,rightNode);
        
    }
};