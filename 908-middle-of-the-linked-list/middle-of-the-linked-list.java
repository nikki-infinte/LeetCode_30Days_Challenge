/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        //usign fast and slow pointer
        ListNode dummy=new ListNode();
        dummy.next=head;
        ListNode fast=dummy;
        ListNode slow=dummy;

        while(fast.next!=null && fast.next.next!=null)
        {
            fast=fast.next.next;
            slow=slow.next;
        } 
      
           
        return slow.next;
        
    }
}