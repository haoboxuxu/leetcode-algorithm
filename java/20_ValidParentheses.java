class Solution {
    public boolean isValid(String s) {
        if(s == null || s.length() == 0)
        	return true;
        Stack<Character> stack = new Stack<Character>();
        
        for(Character ch:s.toCharArray()) {
        	if(ch == '(') {
        		stack.push(')');
        	}else if(ch == '['){
				stack.push(']');
			}else if(ch == '{'){
				stack.push('}');
			}else {
				if(stack.isEmpty() || stack.pop() != ch) {
					return false;
				}
			}
        }
        
        return stack.isEmpty();
    }
}
