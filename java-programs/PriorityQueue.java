public class Priorityqueue {

    public static void main(String[] args) {
       
    }

}

// Implement a priority queue using one of the above implemented linked lists
class PriorityQ {

    static Node head, rear;

    // Linked List Node
    static class Node {

        int data;
        int priority;
        Node prev, next;
    }

    // Function to insert a new Node
    static void push(Node fItem, Node rItem, int n, int p) {
        Node newNode = new Node();
        newNode.data = n;
        newNode.priority = p;

        // If linked list is empty
        if (fItem == null) {
            fItem = newNode;
            rItem = newNode;
            newNode.next = null;
        } else {
          
            if (p <= (fItem).priority) {
                newNode.next = fItem;
                (fItem).prev = newNode.next;
                fItem = newNode;
            } 
            else if (p > (rItem).priority) {
                newNode.next = null;
                (rItem).next = newNode;
                newNode.prev = (rItem).next;
                rItem = newNode;
            } // Handle other cases
            else {

                // Find position where we need to
                // insert.
                Node start = (fItem).next;
                while (start.priority > p) {
                    start = start.next;
                }
                (start.prev).next = newNode;
                newNode.next = start.prev;
                newNode.prev = (start.prev).next;
                start.prev = newNode.next;
            }
        }
        head = fItem;
        rear = rItem;
    }

    // Return the value at rear
    static int peek(Node fItem) {
        return fItem.data;
    }

    static boolean isEmpty(Node fItem) {
        return (fItem == null);
    }

    // Removes the element with the
    // least priority value form the list
    static int pop(Node fItem, Node rItem) {
        Node temp = fItem;
        int res = temp.data;
        (fItem) = (fItem).next;
        if (fItem == null) {
            fItem = null;
        }

        head = fItem;
        rear = rItem;
        return res;
    }
}
