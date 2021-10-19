import java.util.Scanner;

/* class Node {
  int data;
  Node next;
  Node(){}
  Node(int d) {
    data=d;
  }
} */
class Result {
    static int checkPalindrome(Node head) {
      if(head == null)
        return 0;
      Node slow = head;
      Node fast = head;
      Node mid = null;
      while(fast.next != null && fast.next.next != null){
        slow = slow.next;
        fast = fast.next.next;
      }
      if(fast != null)
        mid = slow.next;
      else
        mid = slow;
      Node prev = null;
      while(mid != null){
        Node next = mid.next;
        mid.next = prev;
        prev = mid;
        mid = next;
      }
      while(prev != null){
        if(prev.data != head.data)
          return 0;
        prev = prev.next;
        head = head.next;
      }
      return 1;
    }
  }

  class Node {
    int data;
    Node next;
    Node(){}
    Node(int d) {
      data=d;
    }
  }
  
  class Main
  {
    static Node insertEnd(Node head, int data)
    {
      Node newLink = new Node(data);
      Node last = head;
      newLink.next = null;   // link new node to NULL as it is last node
      if (head == null)  // if list is empty add in beginning.
      {
        head = newLink;
        return head;
      }
      while (last.next != null)  // Find the last node
        last = last.next;
      last.next = newLink;  // Add the node after the last node of list
      return head;
    }
  
    static void forwardPrint(Node head)
    {
      Node current = head; // start at beginning of list
      while(current != null) // until end of list,
      {
        System.out.print(current.data + " "); // print data
        current = current.next; // move to next link
      }
    }
    public static void main(String[] args)
    {
      int t,n,m,x;
      Scanner s = new Scanner(System.in);
      t=Integer.parseInt(s.nextLine().trim());
      while(t>0)
      {
        Node head = null;
        int ans;
        n = s.nextInt();
        while(n>0)
        {
          m = s.nextInt();
          head = insertEnd(head, m);
          n--;
        }
        ans = Result.checkPalindrome(head);
        System.out.println(ans);
        t--;
      }
    }
  }  