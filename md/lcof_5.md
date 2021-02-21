# [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."


限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```java
class Solution {
    public String replaceSpace(String s) {
        int len = s.length();
        char[] arr = new char[len*3];
        int index = 0;
        
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (c == ' ') {
                arr[index++] = '%';
                arr[index++] = '2';
                arr[index++] = '0';
            }else {
                arr[index++] = c;
            }
        }
        
        String res = new String(arr, 0, index);
        return res;
    }
}
```

