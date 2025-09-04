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


    ListNode* reverse(ListNode* root){

        ListNode* curr = root;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* nxx = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nxx;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        

        if(head==nullptr || head->next == nullptr)return true;
        //approach 1 

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow ->next;
            fast = fast ->next->next;
        }

        ListNode* tmp1 = head;
        ListNode* tmp2;
        if(fast == nullptr){
               tmp2 = reverse(slow); 
        }else{
         tmp2 =reverse(slow->next);
        }

        while(tmp2!=nullptr){
            if(tmp1->val != tmp2->val)return false;
            tmp1  = tmp1->next;
            tmp2 = tmp2 ->next;
        }
        return true;




    }
};