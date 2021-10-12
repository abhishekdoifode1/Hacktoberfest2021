class Solution {
    public int countNode(ListNode head){
        ListNode temp = head;
        int len = 0;
        while(temp != null){
            temp = temp.next;
            len++;
        }
        return len;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int k = countNode(head);
        if(n>k)
            return head;
        if(n==k)
            return head.next;
        else{
        int diff = k - n;          
        ListNode prev= null;      
        ListNode curr = head;
            for(int i = 0;i<diff;i++){
                prev = curr;
                curr = curr.next;
            }
            prev.next = curr.next;
            return head;
        }
        
    }
}