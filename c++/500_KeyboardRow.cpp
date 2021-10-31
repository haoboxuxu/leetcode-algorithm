class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string index = "12210111011122000010020202";
        for (auto& word : words) {
            int row = index[tolower(word[0]) - 'a'];
            bool flag = true;
            for (int i = 1; i < word.length(); i++) {
                if (index[tolower(word[i]) - 'a'] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }
};
