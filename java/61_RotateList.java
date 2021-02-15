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
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }


        int len = 1;
        ListNode tail = head;
        while (tail.next != null) {
            len += 1;
            tail = tail.next;
        }
        tail.next = head;

        k %= len;
        int skip = len - k;
        ListNode cur = head;
        for (int i = 0; i < skip - 1; i++) {
            cur = cur.next;
        }
        head = cur.next;
        cur.next = null;
        return head;
    }
}
