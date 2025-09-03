
import java.util.ArrayList;
import java.util.Optional;

public class LinkedList {

    private static class Node {

        int data;
        Node nextNode;

        Node(int data) {
            this.data = data;
            this.nextNode = null;
        }
    }

    private Node head;
    private Node tail;

    public LinkedList() {
        this.head = null;
        this.tail = null;
    }

    public int get(int index) {
        if (index < 0 || index >= listCount()) {
            return -1;
        }

        Node p = head;

        for (int i = 0; i < index; i++) {
            p = p.nextNode;
        }

        return p.data;
    }

    public void insertHead(int val) {

        Node newNode = new Node(val);

        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.nextNode = head;
            head = newNode;
        }
    }

    public void insertTail(int val) {
        Node newNode = new Node(val);

        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.nextNode = newNode;
            tail = newNode;
        }
    }

    public boolean remove(int index) {
        if (index < 0 || index >= listCount()) {
            return false;
        }

        if (index == 0) {
            head = head.nextNode;
            if (head == null) {
                tail = null;
            }
        } else {
            Node p = head;
            Node q = null;

            for (int i = 0; i < index; i++) {
                q = p;
                p = p.nextNode;
            }

            q.nextNode = p.nextNode;

            if (p.nextNode == null) {
                tail = q;
            }
        }

        return true;
    }

    public Optional<ArrayList<Integer>> getValues() {
        ArrayList<Integer> listValues = new ArrayList<>();

        Node p = head;

        if (p == null) {
            return Optional.empty();
        }

        while (p != null) {
            listValues.add(p.data);
            p = p.nextNode;
        }

        return Optional.of(listValues);
    }

    private int listCount() {
        Node p = head;
        int count = 0;

        if (p == null) {
            return 0;
        }

        while (p != null) {
            count++;
            p = p.nextNode;
        }

        return count;
    }

    public static void main(String[] args) {

    }
}
