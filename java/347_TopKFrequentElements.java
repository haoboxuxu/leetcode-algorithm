class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> hs = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        List<Integer>[] list = new List[nums.length+1];
        for(int num : nums){
            if(hs.containsKey(num)) {
            	hs.put(num, hs.get(num) + 1);
            }else {
				hs.put(num, 1);
			}
        }
        
        for(int key : hs.keySet()) {
        	int i = hs.get(key);
        	if(list[i] == null) {
        		list[i] = new ArrayList<Integer>(); 
        	}
        	list[i].add(key);
        }
        
        for(int i = list.length - 1; i >= 0 && res.size() < k; i--) {
        	if(list[i] == null) continue;
            res.addAll(list[i]);
        }
        
        return res;
    }
}
