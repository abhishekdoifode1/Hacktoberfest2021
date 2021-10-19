import java.util.Scanner;

/* class Node {
  int data;
  Node next;
  Node() {}
  Node(int d) {
    data=d;
  }
} */
class Result {
    static Node findMergePoint(Node head1, Node head2){
          int c1 = getCount(head1);
          int c2 = getCount(head2);
          int d;
          if (c1 > c2) {
              d = c1 - c2;
              return getMergePoint(d, head1, head2);
          }
          else {
              d = c2 - c1;
              return getMergePoint(d, head2, head1);
          }
      }
     static Node getMergePoint(int d, Node head1, Node head2){
          int i;
          Node curr1 = head1;
          Node curr2 = head2;
          for (i = 0; i < d; i++)
              curr1 = curr1.next;
          while (curr1 != null && curr2 != null) {
              if (curr1 == curr2)
                  return curr1;
              curr1 = curr1.next;
              curr2 = curr2.next;
          }
          return null;
      }
     static int getCount(Node head){
          Node curr = head;
          int count = 0;
          while (curr != null) {
              count++;
              curr = curr.next;
          }
          return count;
      }
   }

   class Node {
    int data;
    Node next;
    Node() {}
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
  
    public static void main(String[] args) {
      int t,n,m,k;
      Scanner s = new Scanner(System.in);
      t=Integer.parseInt(s.nextLine());
      while(t>0) {
        Node head = null, head2=null, t1, t2, t3;
        n = s.nextInt();
        while(n>0) {
          m = s.nextInt();
          head = insertEnd(head, m);
          n--;
        }
        n = s.nextInt();
        while(n>0) {
          m = s.nextInt();
          head2 = insertEnd(head2, m);
          n--;
        }
        k = s.nextInt();
        if(k>0) {
          t1 = head;
          while(k>0) {
            t1 = t1.next;
            k--;
          }
          t2 = head2;
          while(t2.next != null)
            t2 = t2.next;
          t2.next = t1;
        }
        t3 = Result.findMergePoint(head, head2);
        forwardPrint(t3);
        System.out.println();
        t--;
      }
    }
  }