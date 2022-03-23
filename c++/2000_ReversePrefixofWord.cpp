class Solution {
public:
    string reversePrefix(string word, char ch) {
        int x = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                x = i;
                break;
            }
        }

        for (int i = 0, j = x; i < j; i++, j--) {
            swap(word[i], word[j]);
        }
        return word;
    }
};
