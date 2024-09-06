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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> numSet(nums.begin(),nums.end());
        while (head != nullptr && numSet.find(head->val) != numSet.end()) {
            head = head->next;
        }
        ListNode* tmp=head;
        ListNode* prev=NULL;
        while(tmp!=NULL)
        {
            if(numSet.find(tmp->val)!=numSet.end())
            {
                //remove
                if(prev!=NULL)
                {
                    prev->next=tmp->next;
                }
            }else{
                prev=tmp;
            }
            tmp=tmp->next;
        }
        return head;
    }
};