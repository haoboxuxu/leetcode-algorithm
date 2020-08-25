class Solution {
    public boolean isPalindrome(ListNode head) {
        int len = getListLen(head);
        if (len == 0) {
            return true;
        }

        ListNode mid = head;
        for (int i = 0; i < (len+1) / 2; i++) {
            mid = mid.next;
        }
        mid = reverseKBack(mid);

        return isSameList(len/2, head, mid);
    }

    private int getListLen(ListNode head) {
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            cur = cur.next;
            len += 1;
        }
        return len;
    }

    private ListNode reverseKBack(ListNode head) {
        ListNode dummy = null, cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = dummy;
            dummy = cur;
            cur = next;
        }
        return dummy;
    }

    private boolean isSameList(int len, ListNode list1, ListNode list2) {
        for (int i = 0; i < len; i++) {
            if (list1.val != list2.val) {
                return false;
            }
            list1 = list1.next;
            list2 = list2.next;
        }
        return true;
    }
}
