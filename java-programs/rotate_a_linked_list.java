import java.util.Scanner;
class LinkList
{
  int data;
  LinkList next;
  LinkList(int d)
  {
    data=d;
  }
}

class Main
{
  // Insert in end
  static LinkList insertEnd(LinkList head, int data)
  {
    LinkList newLink = new LinkList(data);
    LinkList last = head;
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

  static void traverse(LinkList first)
  {
    while (first != null)
    {
      System.out.print(first.data + " ");
      first = first.next;
    }
  }

  /* class LinkList
{
  int data;
  LinkList next;
  LinkList prev;
} */
static LinkList rotateList(LinkList head, int k)
{
  if (head == null || k < 1)
          	return head;
      	LinkList newHead = null;
      	LinkList curr = head;
      	int i = 1;
      	while (i < k && curr != null)
      	{
      	    curr = curr.next;
      	    i++;
      	}
      	if (curr == null || curr.next == null)
      	    return head;
      	else
      	{
      	    LinkList kthNode = curr;
      	    curr = curr.next;
            newHead = kthNode.next;
            kthNode.next = null;
      	}
        while (curr.next != null)
            curr = curr.next;
        curr.next = head;
      	return newHead;
}

public static void main(String[] args)
  {
    int t,n,m,x,y;
    String sp;
    Scanner s = new Scanner(System.in);
    LinkList head = null, t1, t2;
    n=Integer.parseInt(s.nextLine().trim());
    while(n>0)
    {
      m = s.nextInt();
      head = insertEnd(head, m);
      n--;
    }
    sp = (s.nextLine().trim());
    int k = s.nextInt();
    t1 = rotateList(head, k);
    traverse(t1);
    System.out.println();
  }
}