# [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)



```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
// 2ms
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        while (lenA > lenB) {
            headA = headA.next;
            lenA -= 1;
        }
        while (lenB > lenA) {
            headB = headB.next;
            lenB -= 1;
        }
        while (headA != null && headB != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
    
    private int getListLen(ListNode head) {
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len += 1;
            cur = cur.next;
        }
        return len;
    }
}
// 1ms
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode posA = headA;
        ListNode posB = headB;

        if (headA == null && headB == null) {
            return null;
        }
        while (posA != posB) {
            posA = posA != null ? posA.next : headB;
            posB = posB != null ? posB.next : headA;
        }
        return posA;
    }
}
```

