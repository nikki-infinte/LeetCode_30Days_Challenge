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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // brute force 
        map<int,int>umap;
        ListNode* tmp = head;
        while(tmp!=nullptr){
            umap[tmp->val]++;
            tmp=tmp->next;
        }

        ListNode* newList =new ListNode(-1);
        ListNode* tmp1 = newList;
        for(auto a:umap){
            if(a.second == 1)
            { tmp1->next = new ListNode(a.first);
            tmp1 = tmp1->next;}
        }
        return newList->next;
        
    }
};