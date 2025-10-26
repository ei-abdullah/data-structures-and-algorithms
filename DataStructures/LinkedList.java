
public class LinkedList {

    private class Node {

        int data;
        Node next;
    }

    Node head;

    void Insert(int index, int value) {
        if (index < 0 || index >= ListCount()) {
            return;
        }

        Node newNode = new Node();
        newNode.data = value;
        newNode.next = null;

        if (index == 0) {
            newNode.next = null;
            head = newNode;
            return;
        }

        Node p = head;
        for (int i = 0; i < index - 1; i++) {
            p = p.next;
        }
        newNode.next = p.next;
        p.next = newNode;
    }

    int FindNode(int value) {
        Node p = head;
        int index = 0;

        while (p != null) {
            if (p.data == value) {
                return index;
            }
            p = p.next;
            index++;
        }

        return -1;
    }

    int DeleteNode(int index) {
        if (index < 0 || index >= ListCount()) {
            return -1;
        }

        Node p = head;
        Node q = null;
        int value = 0;

        if (index == 0) {
            q = head;
            value = head.data;
            head = head.next;
            return value;
        }

        for (int i = 0; i < index; i++) {
            q = p;
            p = p.next;
        }

        q.next = p.next;
        value = p.data;
        return value;
    }

    int ListCount() {
        int count = 0;
        Node p = head;
        while (p != null) {
            count++;
            p = p.next;
        }

        return count;
    }

    public static void main(String[] args) {

    }
}
