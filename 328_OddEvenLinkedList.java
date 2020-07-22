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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }

        ListNode odd = head;
        ListNode even = head.next;
        ListNode t1 = head;
        ListNode t2 = head.next;

        while (t1 != null && t2 != null && t1.next != null && t2.next != null) {
            t1.next = t1.next.next;
            t2.next = t2.next.next;
            t1 = t1.next;
            t2 = t2.next;
        }
        t1.next = even;
        return odd;
    }
}
