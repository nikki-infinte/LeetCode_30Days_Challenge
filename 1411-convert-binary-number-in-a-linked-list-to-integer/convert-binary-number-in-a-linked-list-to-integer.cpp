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
    int getDecimalValue(ListNode* head) {
        int size =0;

        ListNode* tmp = head;
        while(tmp!=nullptr){
            size++;
            tmp=tmp->next;
        }

        tmp = head;
        int ans=0;
        size-=1;
        while(tmp!=nullptr){
            if(tmp->val == 1)
                ans+=pow(2,size);
            tmp=tmp->next;
            size = size-1;
        }
        return ans;
    }
};