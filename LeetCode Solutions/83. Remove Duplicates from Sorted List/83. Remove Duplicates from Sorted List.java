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
    public ListNode deleteDuplicates(ListNode head) {
        
        ListNode temp=new ListNode();
        temp=head;
        ListNode Start=new ListNode();
        Start=null;
        while(temp!=null){
            if(temp.next!=null && temp.val==temp.next.val){
                if(Start==null){
                    Start=temp;
                }
            }
            else{
                if(Start!=null){
                   Start.next=temp.next;
                Start=null;
                }
            }
            temp=temp.next;
        }
        return head;
    }
}