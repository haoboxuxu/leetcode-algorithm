class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size() - 1);
    }

    bool dfs(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int k = l;
        int root = postorder[r];
        while (k < r && postorder[k] < root) k++;
        for (int i = k; i < r; i++) {
            if (postorder[i] < root) return false;
        }
        return dfs(postorder, l, k - 1) && dfs(postorder, k, r - 1);
    }
};