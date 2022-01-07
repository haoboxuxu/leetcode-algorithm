//sol1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == nullptr) return nullptr;
    	auto a = head, b = head->next;
    	while (b) {
    		auto nxt = b->next;
    		b->next = a;
    		a = b;
    		b = nxt;
    	}
    	head->next = nullptr;
    	return a;
    }
};
//sol2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) return head;
    	auto tail = reverseList(head->next);
    	head->next->next = head;
    	head->next = nullptr;
    	return tail;
    }
};
