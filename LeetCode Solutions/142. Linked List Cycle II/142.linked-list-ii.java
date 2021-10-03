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
    public ListNode detectCycle(ListNode head) {
        
        ListNode slowptr=head;
        ListNode fastptr=head;
        int isLoop=0;
        while(fastptr!=null && fastptr.next!=null){
            slowptr=slowptr.next;
            fastptr=fastptr.next.next;
            if(slowptr==fastptr){
                ListNode slowerptr=head;
                while(slowerptr!=slowptr){
                    slowerptr=slowerptr.next;
                    slowptr=slowptr.next;
                }return slowptr;
            }
        }return null;
    }

    }
