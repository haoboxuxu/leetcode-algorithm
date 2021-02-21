# [剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



```java
//quicksort & partition
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        return quickSearch(arr, 0, arr.length - 1, k - 1);
    }

    private int[] quickSearch(int[] nums, int start, int end, int k) {
        int j = partition(nums, start, end);
        if (j == k) {
            return Arrays.copyOf(nums, j + 1);
        }
        return j > k ? quickSearch(nums, start, j - 1, k) : quickSearch(nums, j + 1, end, k);
    }

    private static int partition(int[] arr, int start, int end) {
        int pivot = (int) (start + Math.random() * (end - start + 1));
        int index = start - 1;
        swap(arr, pivot, end);
        for (int i = start; i <= end; i++) {
            if (arr[i] <= arr[end]) {
                index += 1;
                if (i > index) {
                    swap(arr, i, index);
                }
            }
        }
        return index;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
//PriorityQueue
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        Queue<Integer> queue = new PriorityQueue<>((v1, v2) -> v2 - v1);
        for (int a : arr) {
            if (queue.size() < k) {
                queue.offer(a);
            }else if (a < queue.peek()) {
                queue.poll();
                queue.offer(a);
            }
        }
        int[] res = new int[queue.size()];
        int i = 0;
        for (int num : queue) {
            res[i++] = num;
        }
        return res;
    }
}

//treemap
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int cnt = 0;
        for (int a : arr) {
            if (cnt < k) {
                map.put(a, map.getOrDefault(a, 0) + 1);
                cnt++;
                continue;
            }
            Map.Entry<Integer, Integer> entry = map.lastEntry();
            if (entry.getKey() > a) {
                map.put(a, map.getOrDefault(a, 0) + 1);
                if (entry.getValue() == 1) {
                    map.pollLastEntry();
                }else {
                    map.put(entry.getKey(), entry.getValue() - 1);
                }
            }
        }
        int[] res = new int[k];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int v = entry.getValue();
            while (v-- > 0) {
                res[index++] = entry.getKey();
            }
        }
        return res;
    }
}
```

