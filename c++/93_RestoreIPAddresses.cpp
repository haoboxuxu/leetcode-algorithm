class Solution {
private:
    vector<string> res;
    vector<int> segments;
    static constexpr int COUNT = 4;
    
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(COUNT);
        dfs(s, 0, 0);
        return res;
    }
    
    void dfs(const string& s, int segID, int segStart) {
        if (segID == COUNT) {
            if (segStart == s.size()) {
                string ipaddr;
                for (int i = 0; i < COUNT; i++) {
                    ipaddr += to_string(segments[i]);
                    if (i != COUNT-1) {
                        ipaddr += ".";
                    }
                }
                res.push_back(ipaddr);
                //res.push_back(move(ipaddr));
            }
            return;
        }
        
        if (segStart == s.size()) {
            return;
        }
        
        if (s[segStart] == '0') {
            segments[segID] = 0;
            dfs(s, segID+1, segStart+1);
        }
        
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); segEnd++) {
            addr = addr*10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segID] = addr;
                dfs(s, segID+1, segEnd+1);
            } else {
                break;
            }
        }
    }
};
