class Solution {

    private void swapArr(int[] nums1, int[] nums2) {
        int[] temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }


    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length < nums2.length) {
            swapArr(nums1, nums2);
        }
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            if (mp.containsKey(nums1[i])) {
                mp.put(nums1[i], mp.get(nums1[i]) + 1);
            }else {
                mp.put(nums1[i], 1);
            }
        }

        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < nums2.length; i++) {
            if (mp.containsKey(nums2[i])) {
                mp.put(nums2[i], mp.get(nums2[i]) - 1);
                if (mp.get(nums2[i]) >= 0) {
                    list.add(nums2[i]);
                }
            }
        }

        int[] res = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }

        return res;
    }
}
