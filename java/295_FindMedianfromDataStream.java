class MedianFinder {
	private PriorityQueue<Integer> maxHeap, minHeap;
    /** initialize your data structure here. */
    public MedianFinder() {
        maxHeap = new PriorityQueue<Integer>(Collections.reverseOrder());
        minHeap = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());
        if(maxHeap.size() < minHeap.size()) {
        	maxHeap.add(minHeap.poll());
        }
    }
    
    public double findMedian() {
    	if(maxHeap.size() == minHeap.size()) {
    		return (maxHeap.peek() + minHeap.peek()) * 0.5;
    	}else{
    		return maxHeap.peek();
    	}
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
