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

    ListNode* reverse(ListNode* node){
        ListNode* curr = node;
        ListNode* pre = nullptr;

        while(curr !=nullptr)
        {   ListNode* nxt = curr->next;
            curr->next=pre;
            pre= curr;
            curr = nxt;
        }
        return pre;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        head = reverse(head);
        ListNode* tmp = head;
        if(n==1){
            head = head->next;
            delete (tmp);
        }else{

            for(int i=1;i<n-1;i++){
                tmp=tmp->next;
            }
            ListNode* toBeDeleted = tmp->next;
            tmp->next = tmp->next->next;
            delete(toBeDeleted);
        }



    head = reverse(head);
    return head;

    }
};