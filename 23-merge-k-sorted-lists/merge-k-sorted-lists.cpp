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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.empty())
            return NULL;

        // Priority queue to store pairs of (node value, index of list)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Push the head of each list into the priority queue
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                pq.push({lists[i]->val, i});
            }
        }

        if(pq.empty())
            return NULL;

        // Create a dummy node to start the merged list
        ListNode* temp = new ListNode();
        ListNode* head = temp;

        while(true) {
            // Get the smallest element from the priority queue
            auto it = pq.top();
            pq.pop();

            // Set the current node's value
            temp->val = it.first;

            // Move to the next node in the list from which the smallest element was extracted
            if(lists[it.second]->next != nullptr) {
                lists[it.second] = lists[it.second]->next;
                pq.push({lists[it.second]->val, it.second});
            }

            // If the priority queue is not empty, create a new node for the merged list
            if(!pq.empty()) {
                temp->next = new ListNode();
                temp = temp->next;
            } else {
                break;
            }
        }

        return head;
    
    }
};