class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet hs = new HashSet(wordList);
        if(hs.contains(beginWord)){
            hs.remove(beginWord);
        }
        
        int level = 1;
        int curNum = 1;
        int nxtNum = 0;
        Queue<String> q = new LinkedList<String>();
        q.offer(beginWord);
        while(!q.isEmpty()){
            String word = q.poll();
            curNum--;
            for(int i = 0; i < word.length(); i++){
                char[] curWord = word.toCharArray();
                for(char j = 'a'; j <= 'z'; j++){
                    curWord[i] = j;
                    String nowWord = new String(curWord);
                    if(hs.contains(nowWord)){
                        if(nowWord.equals(endWord)){
                            return level + 1;
                        }
                        nxtNum++;
                        q.offer(nowWord);
                        hs.remove(nowWord);
                    }
                }
            }
            if(curNum == 0){
                curNum = nxtNum;
                nxtNum = 0;
                level++;
            }
        }
        return 0;
    }
}
