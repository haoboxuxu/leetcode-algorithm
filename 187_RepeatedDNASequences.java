//simple but slow
/*
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
    	HashSet<String> hs = new HashSet<String>();
    	HashSet<String> res = new HashSet<String>();
//        if(s.length() <= 10) return res;
        
        for(int i = 0; i < s.length() - 9; i++) {
        	String cur = s.substring(i, i+10);
        	if(hs.contains(cur)) {
        		res.add(cur);
        	}else {
        		hs.add(cur);
        	}
        }
        return new LinkedList<String>(res);
    }
}
*/
