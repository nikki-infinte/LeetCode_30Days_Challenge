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
    ListNode* solve(ListNode* curr,ListNode*nxt,ListNode* prev)
    {
        if(curr==NULL)
        {
            return prev;
        }

        nxt=curr->next;
        curr->next=prev;
        return solve(nxt,nxt,curr);

    }
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*nxt=NULL;
        ListNode*prev=NULL;
        return solve(curr,nxt,prev);

    }
};