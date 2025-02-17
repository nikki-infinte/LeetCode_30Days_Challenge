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
    ListNode* deletehead(ListNode* head)
    {
        if(!head ) return NULL;
        ListNode* tmp =head->next;
        delete(head);
        return tmp;
    }
    ListNode* deletetail(ListNode* head) {
        if (!head || !head->next) {  // If list is empty or has only one node
            delete head;
            return nullptr;
        }
        ListNode* tmp = head;
        while (tmp->next->next != nullptr) {  // Stop at second last node
            tmp = tmp->next;
        }
        delete tmp->next;  // Delete last node
        tmp->next = nullptr;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head )return NULL;
        //using brute force 

        int l=0;
        ListNode* tmp=head;
        while(tmp)
        {
            l++;
            tmp=tmp->next;
        }
      if (n > l) return head; 
        if( l == n){
            return deletehead(head);
        }
        if( n == 1)
        {
            return deletetail(head);
        }


        int  t = l-n;
        tmp=head;
         for (int i = 1; i < t ;i++) {  // Move exactly (length-n-1) steps
            tmp = tmp->next;
        }

        ListNode* currn =tmp->next;
        tmp->next = currn->next;
        delete currn;
        return head;

    }
};