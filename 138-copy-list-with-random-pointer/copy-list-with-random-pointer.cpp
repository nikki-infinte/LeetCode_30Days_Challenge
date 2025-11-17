/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==nullptr)return nullptr;

        Node*curr = head;
        while(curr){
            Node* curNxt  = curr->next;
            curr->next = new Node(curr->val); 
            curr->next->next = curNxt;
            curr = curNxt;
        }

        // step 2 :  
        curr = head;
        while(curr){

            if(curr->random == nullptr){
                curr->next -> random =nullptr;
            }else{
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        //step 3 
        
        Node* newhead = head->next;
        Node* newcurr = newhead;
        curr = head;

        while(curr && newcurr ){

            curr->next = curr->next == nullptr ? nullptr : curr->next->next;
            newcurr->next = newcurr->next == nullptr ? nullptr : newcurr->next->next;


            curr =curr->next;
            newcurr = newcurr->next;
        }

        return newhead;
    }
};