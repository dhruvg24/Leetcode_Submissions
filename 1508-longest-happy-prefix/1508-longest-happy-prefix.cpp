class Solution {
public:
    string longestPrefix(string s) {
        // KMP
        int n=s.size();
        if(n==0)
            return "";
        vector<int> pref(n,0);
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j])
                pref[j]=i+1, i++, j++;
            else
            {
                if(i==0)
                    j++;
                else
                 i = pref[i-1];
            }
        }
        return s.substr(0,i);
    }
};
