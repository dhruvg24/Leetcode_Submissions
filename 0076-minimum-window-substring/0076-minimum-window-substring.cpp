class Solution {
public:
string minWindow(string s, string t) {
        unordered_map<char,int> mps,mpt;
        for(auto it:t)
        // store the freq of char in string t
        {
            mpt[it]++;
        }
        int k = mpt.size();
        // window sz = num of uniqe char in t
        int ct = 0;
        int ans = s.size();
        string res = "";

        int i = 0,j = 0;

        while(j<s.size())
        {
            mps[s[j]]++;
            if(mps[s[j]] == mpt[s[j]]) ct++;

            while(i<j and mps[s[i]] > mpt[s[i]])
            {
                mps[s[i++]]--;
            }

            if(ct == k)
            {
                if(j-i+1 <= ans)
                {
                    // min string
                    ans = j-i+1;
                    res = s.substr(i,j-i+1);
                }
                mps[s[i]]--;
                ct--;
                i++;
            }
            j++;
        }
        return res;
    }
};

