class Solution {
    public int[] dailyTemperatures(int[] T) {
        Stack<Integer> s = new Stack<>();
        int[] res = new int[T.length];
        for(int i = 0; i < T.length; i++) {
            while (!s.empty() && T[s.peek()] < T[i]) {
                int top = s.pop();
                res[top] = i - top;
            }
            s.push(i);
        }
        return res;
    }
}
