/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode* ,int> umap; 
    ListNode* tmp=head;

    while(tmp!=NULL)
    {
        if(umap.find(tmp)!=umap.end())
        {
            return tmp;
        }
        else{
            umap[tmp]=1;
        }
        tmp=tmp->next;
    }
    return NULL;
    }
};