// sol1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> vis;
        
        ListNode* temp = headA;
        while (temp != nullptr) {
            vis.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while (temp != nullptr) {
            if (vis.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        
        return nullptr;
    }
};
// sol2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        
        return pA;
    }
};
