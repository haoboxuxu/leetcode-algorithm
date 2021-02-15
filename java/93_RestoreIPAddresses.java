class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        helper(res, s, 0, "", 0);
        return res;
    }
    public void helper(List<String> res, String s, int index, String ret, int cnt){
        if(cnt > 4) return;
        if(cnt == 4 && index == s.length()){
            res.add(ret);
            return;
        }
        for(int i = 1; i <= 3; i++){
            if(index + i > s.length()) break;
            String temp = s.substring(index, index + i);
            if((temp.charAt(0) == '0' && temp.length() > 1) || (i == 3 && Integer.parseInt(temp) >= 256)){
                continue;
            }
            helper(res, s, index + i, ret + temp + (cnt == 3 ? "" :"."), cnt+1);
        }
    }
}
