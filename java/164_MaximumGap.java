class Solution {
	class Bucket{
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
	}
    public int maximumGap(int[] nums) {
        if(nums.length < 2 || nums == null) return 0;
        int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for(int i = 0;  i < nums.length; i++){
			min = Math.min(min, nums[i]);
        	max = Math.max(max, nums[i]);
		}

		int bucketSize = Math.max((max - min) / (nums.length - 1), 1);
		int bucketNum = (max - min) / bucketSize + 1;
		Bucket[] buckets = new Bucket[bucketNum];

		for(int i = 0;  i < nums.length; i++){
			int location = (nums[i] - min) / bucketSize;
			if(buckets[location] == null){
				buckets[location] = new Bucket();
			}
			buckets[location].min = Math.min(buckets[location].min, nums[i]);
			buckets[location].max = Math.max(buckets[location].max, nums[i]);
		}

		int maxGap = Integer.MIN_VALUE;
		int preMaxGap = Integer.MAX_VALUE;

		for(int i = 0; i < buckets.length; i++){
			if(buckets[i] != null && preMaxGap != Integer.MAX_VALUE){
				maxGap = Math.max(maxGap, buckets[i].min - preMaxGap);
			}

			if(buckets[i] != null){
				preMaxGap = buckets[i].max;
				maxGap = Math.max(maxGap, buckets[i].max - buckets[i].min);
			}
		}
		return maxGap;
    }
}
