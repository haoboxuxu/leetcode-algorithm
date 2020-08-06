class Solution {
    Map<Integer, Integer> map = new HashMap<>();

    public int numTrees(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }
        if (n <= 1) {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int leftNum = numTrees(i - 1);
            int rightNum = numTrees(n - i);
            res += (leftNum * rightNum);
        }
        map.put(n, res);
        return res;
    }
}
