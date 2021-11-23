class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = helper(head, nullptr);
        return root;
    }
    
    TreeNode* helper(ListNode* l, ListNode* r) {
        if (l == r) return nullptr;
        ListNode* mid = getmid(l, r);
        TreeNode* root = new TreeNode(mid->val);
        root->left = helper(l, mid);
        root->right = helper(mid->next, r);
        return root;
    }
    
    ListNode* getmid(ListNode* l, ListNode* r) {
        ListNode* fast = l;
        ListNode* slow = l;
        while (fast != r && fast->next != r) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
