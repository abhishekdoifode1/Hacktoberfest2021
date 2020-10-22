/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slowptr=head;
        ListNode fastptr=head;
        int isLoop=0;
        while(fastptr!=null && fastptr.next!=null){
            slowptr=slowptr.next;
            fastptr=fastptr.next.next;
            if(slowptr==fastptr){
                isLoop=1;
                break;
            }
        }if(isLoop==1){return true;}else{return false;}
    }
}