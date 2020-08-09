/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
//循环（开空间）
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = null;
        while (head != null) {
            ListNode temp = new ListNode(head.val);
            temp.next = dummy;
            dummy = temp;
            head = head.next;
        }
        return dummy;
    }
}
//循环（不开空间）
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = null, cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = dummy;
            dummy = cur;
            cur = next;
        }
        return dummy;
    }
}
//递归
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return dummy;
    }
}
