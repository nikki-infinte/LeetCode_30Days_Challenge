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
    ListNode* reverseNode(ListNode* l1)
    {
        ListNode* curr = l1;
        ListNode* pre = nullptr;
       

        while(curr!=nullptr){
           ListNode* nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr =nxt;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    //    l1 = reverseNode(l1);
    //    l2 = reverseNode(l2);

       int carry=0;
       ListNode* newtmp=new ListNode(-1);
       ListNode* ans = newtmp;
       while(l1 != nullptr || l2 != nullptr||carry )
       {
        int sum = carry;
        if(l1!=nullptr){
            sum+=l1->val;
            l1=l1->next;
        }

        if(l2 != nullptr){
            sum+=l2->val;
            l2=l2->next;
        }
        newtmp->next = new ListNode(sum%10);
        newtmp = newtmp->next;
        carry = sum/10;
       }

     
       // ListNode* res = reverseNode(ans->next);
        return ans->next;
    }
};