class Node {
    int key, val;
    Node prev, next;
    Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class MyLinkedList {
    Node head, tail;

    public void push(Node node) {
        node.next = head;
        node.prev = null;
        if (head == null) {
            tail = node;
        }else {
            head.prev = node;
        }
        head = node;
    }

    public void remove(Node node) {
        if (node == head) {
            head = node.next;
        }
        if (node == tail) {
            tail = node.prev;
        }
        if (node.next != null) {
            node.next.prev = node.prev;
        }
        if (node.prev != null) {
            node.prev.next = node.next;
        }
    }
}

class LRUCache {

    private Map<Integer, Node> cache = new HashMap<>();
    private int capacity;
    private MyLinkedList linkedList = new MyLinkedList();

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            linkedList.remove(node);
            linkedList.push(node);
            return node.val;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            linkedList.remove(cache.get(key));
        }else if (cache.size() >= capacity) {
            Node lru = linkedList.tail;
            cache.remove(lru.key);
            linkedList.remove(lru);
        }

        Node node = new Node(key, value);
        cache.put(key, node);
        linkedList.push(node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
