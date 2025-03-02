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

      //brute  force 

      vector<int>tmp;
      ListNode* b = head;
      while(b!=NULL)
      {
        tmp.push_back(b->val); 
        b=b->next;
      }

     

     ListNode* curr =head;
      int i=0,j=tmp.size()-1;

      while(i < j)
      {
        curr ->val =tmp[i];
        curr = curr->next;
        curr->val = tmp[j];
        curr =curr ->next;
        i++;
        j--;
      }
      if( i== j)curr->val = tmp[i];
     

    }



   
};