class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length < 2) {
            return intervals;
        }

        List<int[]> res = new ArrayList<>();
        Arrays.sort(intervals, (arr1, arr2) -> Integer.compare(arr1[0], arr2[0]));

        int[] cur = intervals[0];
        res.add(cur);

        for (int[] interval : intervals) {
            int curEnd = cur[1];
            int nextStart = interval[0];
            int nextEnd = interval[1];
            if (curEnd >= nextStart) {
                cur[1] = Math.max(nextEnd, curEnd);
            } else {
                res.add(interval);
                cur = interval;
            }
        }

        return res.toArray(new int[res.size()][]);
    }
}
