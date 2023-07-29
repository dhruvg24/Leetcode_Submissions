class Solution {
public:
    int ans=0;
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }

    void DFS(int idx, string &s, string &s1, string &s2){
        if(idx>=s.size()){
            if(isPalindrome(s1)&&isPalindrome(s2))
                ans = max(ans,(int)s1.size()*(int)s2.size());
            return;
        }
        s1.push_back(s[idx]);
        DFS(idx+1,s,s1,s2);
        s1.pop_back();

        s2.push_back(s[idx]);
        DFS(idx+1,s,s1,s2);
        s2.pop_back();

        // dont pick at all
        DFS(idx+1, s, s1, s2);


    }
    int maxProduct(string s) {
        string str1="", str2="";
        // if idx is chosen for str1 cant be chosen for str2 other case being vice versa, or donot pick idx at all for both the string-> explore further using DFS call
        DFS(0,s, str1, str2);
        return ans;
    }
};


