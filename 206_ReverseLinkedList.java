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
