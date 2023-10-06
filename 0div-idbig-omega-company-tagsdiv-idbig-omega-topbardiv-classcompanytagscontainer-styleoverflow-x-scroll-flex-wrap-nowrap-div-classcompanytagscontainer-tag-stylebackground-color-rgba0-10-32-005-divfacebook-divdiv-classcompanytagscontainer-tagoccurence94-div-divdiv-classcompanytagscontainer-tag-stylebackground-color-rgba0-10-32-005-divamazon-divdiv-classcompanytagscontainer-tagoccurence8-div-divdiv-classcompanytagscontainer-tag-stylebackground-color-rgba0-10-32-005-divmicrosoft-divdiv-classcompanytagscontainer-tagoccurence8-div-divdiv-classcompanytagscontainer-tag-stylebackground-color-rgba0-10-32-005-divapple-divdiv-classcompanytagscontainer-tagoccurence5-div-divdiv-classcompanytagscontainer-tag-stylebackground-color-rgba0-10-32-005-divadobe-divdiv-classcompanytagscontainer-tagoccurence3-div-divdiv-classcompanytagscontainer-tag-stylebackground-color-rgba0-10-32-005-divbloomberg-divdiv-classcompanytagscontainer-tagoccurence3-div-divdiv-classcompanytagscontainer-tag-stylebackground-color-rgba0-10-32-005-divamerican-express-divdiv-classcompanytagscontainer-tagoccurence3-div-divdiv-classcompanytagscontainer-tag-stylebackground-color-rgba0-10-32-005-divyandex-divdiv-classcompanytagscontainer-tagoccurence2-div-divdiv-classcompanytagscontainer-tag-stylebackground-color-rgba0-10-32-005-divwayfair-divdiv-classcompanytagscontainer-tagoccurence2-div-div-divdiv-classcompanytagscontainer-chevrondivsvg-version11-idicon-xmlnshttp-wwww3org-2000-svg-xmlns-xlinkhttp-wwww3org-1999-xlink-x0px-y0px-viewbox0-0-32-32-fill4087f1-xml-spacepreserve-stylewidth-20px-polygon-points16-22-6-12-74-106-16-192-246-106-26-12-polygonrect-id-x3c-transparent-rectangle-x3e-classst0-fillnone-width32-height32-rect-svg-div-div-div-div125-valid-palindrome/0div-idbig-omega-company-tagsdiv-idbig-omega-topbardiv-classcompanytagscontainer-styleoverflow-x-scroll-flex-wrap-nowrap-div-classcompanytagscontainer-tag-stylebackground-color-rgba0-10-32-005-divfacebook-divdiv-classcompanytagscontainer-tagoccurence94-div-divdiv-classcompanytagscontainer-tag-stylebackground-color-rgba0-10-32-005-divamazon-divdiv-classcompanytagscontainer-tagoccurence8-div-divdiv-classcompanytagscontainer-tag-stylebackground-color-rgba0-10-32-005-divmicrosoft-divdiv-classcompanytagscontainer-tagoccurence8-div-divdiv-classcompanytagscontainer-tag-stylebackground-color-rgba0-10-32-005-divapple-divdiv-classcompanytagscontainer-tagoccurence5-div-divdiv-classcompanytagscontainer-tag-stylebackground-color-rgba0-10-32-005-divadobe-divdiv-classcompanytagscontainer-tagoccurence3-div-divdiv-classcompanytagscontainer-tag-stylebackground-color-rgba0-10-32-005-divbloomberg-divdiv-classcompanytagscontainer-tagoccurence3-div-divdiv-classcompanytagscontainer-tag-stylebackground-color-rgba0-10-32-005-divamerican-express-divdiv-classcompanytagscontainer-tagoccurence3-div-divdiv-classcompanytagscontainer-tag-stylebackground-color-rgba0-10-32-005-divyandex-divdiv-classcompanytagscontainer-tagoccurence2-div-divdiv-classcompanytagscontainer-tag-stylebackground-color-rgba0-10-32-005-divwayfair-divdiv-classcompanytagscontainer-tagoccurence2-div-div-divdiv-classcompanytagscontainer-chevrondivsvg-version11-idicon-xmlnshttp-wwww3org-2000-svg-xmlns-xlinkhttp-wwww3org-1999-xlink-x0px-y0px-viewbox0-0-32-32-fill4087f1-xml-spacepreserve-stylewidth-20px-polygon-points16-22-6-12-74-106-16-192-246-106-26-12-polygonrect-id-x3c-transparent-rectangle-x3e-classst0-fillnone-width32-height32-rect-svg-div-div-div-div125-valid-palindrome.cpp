class Solution {
public:
    bool isPalindrome(string s) {
//         lower case to be considered
        int n = s.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(!isalnum(s[i])){
//                 only consider alphanumeric digits
                i++;continue;
            }
            if(!isalnum(s[j])){
                j--;continue;
            }
            if(tolower(s[i])!=tolower(s[j]))
                return false;
            else
                i++,j--;
        }
        return true;
    }
};
