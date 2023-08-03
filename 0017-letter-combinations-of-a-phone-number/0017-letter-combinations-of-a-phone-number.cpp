class Solution {
public:
    int n;
    vector<string> res;
    // store the {num, char}
    vector<vector<char>> mp = {{}, {}, {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    void solve(int idx, string &digits, string tmp){
        if(idx==n){
            res.push_back(tmp);
            return;
        }

        int curNum = digits[idx] - '0';
        for(auto it: mp[curNum])
            solve(idx+1, digits,tmp+it);

    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n==0)
            return {};
        solve(0, digits, "");

        return res;
    }
};