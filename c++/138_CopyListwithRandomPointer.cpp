//sol1
class Solution {
public:
    unordered_map<Node*, Node*> cache;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if (!cache.count(head)) {
            Node* newHead = new Node(head->val);
            cache[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }
        return cache[head];
    }
};
//sol2
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }
        
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = node->next;
            newNode->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        
        Node* newHead = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* newNode = node->next;
            node->next = node->next->next;
            newNode->next = (newNode->next != nullptr) ? newNode->next->next : nullptr;
        }
        
        return newHead;
    }
};
