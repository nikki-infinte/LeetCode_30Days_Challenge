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

    struct compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue< ListNode*, vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* tmp = lists[i];
            while(tmp!=NULL)
            {
                pq.push(tmp);
                tmp = tmp->next;
            }
        }
        ListNode*head=new ListNode(-1);
        ListNode* tmp = head;
        while(!pq.empty())
        {
            tmp->next = pq.top();
            
            pq.pop();
            tmp=tmp->next;
        }
        tmp->next = nullptr;
        return head->next;
    }
};