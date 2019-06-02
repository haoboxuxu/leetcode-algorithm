/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len = getListLen(head);
        if(head == null || (len == 1 && n == 1)) {
        	return null;
        }
        ListNode res = head;
        
        if(len == n) {
        	res = head.next;
        	return res;
        }
        
        for(int i = 0; i < len - n - 1; i++) {
        	head = head.next;
        }
        head.next = head.next.next;
        return res;
    }
    
    public int getListLen(ListNode head) {
    	int len = 0;
    	while(head != null) {
    		head = head.next;
    		len++;
    	}
    	return len;
    }
}
