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
    bool isPalindrome(ListNode* head) {
        //using stack

        stack<int>st;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            st.push(tmp->val);
            tmp=tmp->next;
        }

        ListNode* tmp1=head;
        while( tmp1->next!=NULL)
        {
            if(tmp1->val!=st.top())
            {
                return false;
            }
            st.pop();
            tmp1=tmp1->next;
        }
        return true;
    }
};