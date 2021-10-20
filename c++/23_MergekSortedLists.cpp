//sol1
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
    
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if (!a || !b) return a ? a : b;
        ListNode head, *tail = &head, *pa = a, *pb = b;
        while (pa && pb) {
            if (pa->val < pb->val) {
                tail->next = pa;
                pa = pa->next;
            } else {
                tail->next = pb;
                pb = pb->next;
            }
            tail = tail->next;
        }
        tail->next = pa ? pa : pb;
        return head.next;
    }
};
//sol2
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = l+(r-l)/2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }
    
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if (!a || !b) return a ? a : b;
        ListNode head, *tail = &head, *pa = a, *pb = b;
        while (pa && pb) {
            if (pa->val < pb->val) {
                tail->next = pa;
                pa = pa->next;
            } else {
                tail->next = pb;
                pb = pb->next;
            }
            tail = tail->next;
        }
        tail->next = pa ? pa : pb;
        return head.next;
    }
};
//sol3
class Solution {
public:
    struct Status {
        int val;
        ListNode* p;
        bool operator < (const Status& rs) const {
            return val > rs.val;
        }
    };
    
    priority_queue<Status> pq;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto head : lists) {
            if (head) {
                pq.push({head->val, head});
            }
        }
        
        ListNode head, *tail = &head;
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            tail->next = f.p;
            tail = tail->next;
            if (f.p->next) {
                pq.push({f.p->next->val, f.p->next});
            }
        }
        return head.next;
    }
};
