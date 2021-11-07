class Solution {
public:
    string simplifyPath(string path) {
        string res = "", cur = "";
        if (path.back() != '/') path.push_back('/');
        
        for (auto c : path) {
            if (c != '/') {
                cur += c;
            } else {
                if (cur == "..") {
                    while (!res.empty() && res.back() != '/') res.pop_back();
                    if (res.size() > 0 ) res.pop_back();
                } else if (cur == "." || cur == "") {
                    //
                } else{
                    res += "/" + cur;
                }
                cur.clear();
            }
        }
        
        if (res.empty()) res.push_back('/');
        
        return res;
    }
};
