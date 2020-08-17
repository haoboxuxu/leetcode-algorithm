class Solution {
    public String removeKdigits(String num, int k) {
        if (k == num.length()) {
            return  "0";
        }
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < num.length(); i++) {
            if (stack.size() == 0 && num.charAt(i) != '0') {
                stack.push(num.charAt(i));
            }else {
                while (!stack.isEmpty() && k > 0 && stack.peek() > num.charAt(i)) {
                    stack.pop();
                    k--;
                }
                if(stack.size()==0 && num.charAt(i) =='0') continue;
                stack.push(num.charAt(i));
            }
        }
        while (k-- != 0) {
            stack.pop();
        }
        if(stack.size() == 0) {
            return "0";
        }
        String res = "";
        while (!stack.isEmpty()) {
            res = stack.peek() + res;
            stack.pop();
        }
        return res;
    }
}
