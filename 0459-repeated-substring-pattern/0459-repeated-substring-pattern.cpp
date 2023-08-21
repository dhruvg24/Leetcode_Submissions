class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string cs = s + s;
        if(cs.substr(1, 2*s.size()-2).find(s)!=-1){
            return true;
        }
        return false;
    }
};