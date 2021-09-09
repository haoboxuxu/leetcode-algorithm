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

```c++
//sol2
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr, 0, (int)arr.size()-1, k);
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
    
    void quick_sort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int i = l-1, j = r+1, x = arr[(l+r)>>1];
        while (i < j) {
            do i++; while(arr[i] < x);
            do j--; while(arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        
        int len = j - l + 1;
        
        if (k == len) {
            return;
        } else if (k < len) {
            quick_sort(arr, l, j, k);
        } else if (k > len) {
            quick_sort(arr, j+1, r, k-len);
        }
    }
};
//sol1
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> v(k, 0);
        if (k == 0) return v;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            v[i] = pq.top();
            pq.pop();
        }
        return v;
    }
};
```



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

