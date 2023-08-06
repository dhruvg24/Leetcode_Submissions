class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        for(int i = n - 2;i >= 0; i--){
            if(s[i] == s[n - 1]){
                int start = i;
                int end = n - 1;
                while(start>=0 && end>=start){
                    if(s[start] != s[end])
                        break;
                    start--;
                    end--;
                }
                if(start <0)
                    return s.substr(0, i + 1);
            }
        }
        return "";
    }
};