class Solution {
public:
    string reorganizeString(string s) {
        // if most freq char is present > n/2 times -> return ""
        vector<int> freq(26, 0);
        for(char it: s){
            freq[it-'a']++;
        }
        int n = s.size();
        // char mostFreqCh = 
        int maxFreq = 0;
        int maxChar = 0;
        for(int i=0;i<freq.size();i++){
            if(maxFreq<freq[i]){
                maxFreq = freq[i];
                maxChar = i;
            }
        }
        // cout<<maxFreq<<" ";
        if(maxFreq>(n+1)/2){
            return "";
        }
        string res = s;
        int idx = 0;
        // place the most freq char first
        while(freq[maxChar]!=0){
            res[idx] = char(maxChar+'a');
            idx+=2;
            freq[maxChar]--;
        }
        // place the other char in between the already placed max freq char
        for(int i=0;i<freq.size();i++){
            while(freq[i]>0){
                if(idx>=n){
                    idx = 1;
                }
                res[idx] = char(i + 'a');
                idx+=2;
                freq[i]--;
            }
        }
        return res;

    }
};