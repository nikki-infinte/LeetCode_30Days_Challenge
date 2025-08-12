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
    ListNode* reverseLL(ListNode* head){
        if(head ==nullptr || head->next==nullptr)return head;

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    void reorderList(ListNode* head) {
          if (!head || !head->next) return;
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while(fast  && fast->next != nullptr){
        //     slow = slow->next;
        //     fast = fast->next->next;

        // }

        // ListNode* rev = reverseLL(slow);
        // ListNode* curr = head;

        // while(rev->next != nullptr){


        //     ListNode* tmp = curr->next;
        //     ListNode* revtmp = rev->next;

        //     curr->next = rev;
        //     rev->next = tmp;

        //     curr = tmp;
        //     rev = revtmp;
        // }        


        stack<ListNode*>st;
        ListNode* tmp = head;
        while(tmp){
            st.push(tmp);
            tmp=tmp->next;
        }

        ListNode* curr =head;
        int mid= st.size()/2;

        while (mid--) {
            ListNode* next = curr->next;
            ListNode* tail = st.top(); st.pop();

            curr->next = tail;
            tail->next = next;
            curr = next;
    }
        curr->next = nullptr;

    }
};