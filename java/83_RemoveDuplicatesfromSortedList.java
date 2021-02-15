/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
			return head;
		}
        ListNode res = head;
        while(head.next != null) {
        	if(head.val == head.next.val) {
        		head.next = head.next.next;
        	}else {
				head = head.next;
			}
        }
        
        return res;
    }
}
