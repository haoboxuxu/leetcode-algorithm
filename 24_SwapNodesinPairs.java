/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode l1 = temp;
        ListNode l2 = head;
        while(l2 != null && l2.next != null) {
        	ListNode nextPositio = l2.next.next;
        	l1.next = l2.next;
        	l2.next.next = l2;
        	l2.next = nextPositio;
        	l1 = l2;
        	l2 = l2.next;
        }
        return temp.next;
    }
}
