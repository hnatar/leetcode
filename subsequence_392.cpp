class Solution {
public:
    bool isSubsequence(string s, string t) {
        if( s.empty() ) {
            return true;
        }
        int match_len = 0;
        for(auto &c: t) {
            if( c == s[match_len] ) {
                match_len++;
                if( match_len == s.size() ) {
                    return true;
                }
            }
        }
        return false;
    }
};