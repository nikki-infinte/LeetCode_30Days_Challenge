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
    void reorderList(ListNode* head) {
        // brute force

        vector<int> tmpArr;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            tmpArr.push_back(tmp->val);
            tmp = tmp->next;
        }

        int i = 0, j = tmpArr.size() - 1;
        ListNode* tmp2 = head;
        while (i <= j) {
            tmp2->val = tmpArr[i];
            i++;
            tmp2 = tmp2->next;

            if (i <= j) {
                tmp2->val = tmpArr[j--];
                tmp2 = tmp2->next;
            }
        }
    }
};