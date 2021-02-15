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
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
    	Set<Integer> s1 = new HashSet<Integer>();
    	Set<Integer> s2 = new HashSet<Integer>();
    	List<String> res = new LinkedList<String>();
    	
    	char[] c2i = new char[26];
    	c2i['A' - 'A'] = 0;
    	c2i['C' - 'A'] = 1;
    	c2i['G' - 'A'] = 2;
    	c2i['T' - 'A'] = 3;
    	
    	for(int i = 0; i < s.length() - 9; i++) {
    		int cur = 0;
    		for(int j = i; j < i + 10; j++) {
    			cur <<= 2;
    			cur |= c2i[s.charAt(j) - 'A'];
    		}
    		if(!s1.add(cur) && s2.add(cur)) {
    			res.add(s.substring(i, i+10));
    		}
    	}
    	
    	
    	return res;
    }
}
