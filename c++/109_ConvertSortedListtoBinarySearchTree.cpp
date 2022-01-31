class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        if (n == 1) return new TreeNode(head->val);

        auto cur = head;
        for (int i = 0; i < n / 2 - 1; i++) cur = cur->next;

        auto root = new TreeNode(cur->next->val);
        root->right = sortedListToBST(cur->next->next);
        cur->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};