class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quicksort(arr, 0, arr.size() - 1, k);
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = arr[i];
        return res;
    }

    void quicksort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int i = l - 1, j = r + 1, x = arr[l + r >> 1];
        while (i < j) {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        int len = j - l + 1;
        if (k <= len) quicksort(arr, l, j, k);
        else quicksort(arr, j + 1, r, k - len);
    }
};