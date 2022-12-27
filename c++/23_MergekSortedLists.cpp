class Solution {
public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        auto dummy = new ListNode(-1), cur = dummy;

        for (auto list : lists) if (list) heap.push(list);

        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            cur = cur->next = t;
            if (t->next) heap.push(t->next);
        }

        return dummy->next;
    }
};