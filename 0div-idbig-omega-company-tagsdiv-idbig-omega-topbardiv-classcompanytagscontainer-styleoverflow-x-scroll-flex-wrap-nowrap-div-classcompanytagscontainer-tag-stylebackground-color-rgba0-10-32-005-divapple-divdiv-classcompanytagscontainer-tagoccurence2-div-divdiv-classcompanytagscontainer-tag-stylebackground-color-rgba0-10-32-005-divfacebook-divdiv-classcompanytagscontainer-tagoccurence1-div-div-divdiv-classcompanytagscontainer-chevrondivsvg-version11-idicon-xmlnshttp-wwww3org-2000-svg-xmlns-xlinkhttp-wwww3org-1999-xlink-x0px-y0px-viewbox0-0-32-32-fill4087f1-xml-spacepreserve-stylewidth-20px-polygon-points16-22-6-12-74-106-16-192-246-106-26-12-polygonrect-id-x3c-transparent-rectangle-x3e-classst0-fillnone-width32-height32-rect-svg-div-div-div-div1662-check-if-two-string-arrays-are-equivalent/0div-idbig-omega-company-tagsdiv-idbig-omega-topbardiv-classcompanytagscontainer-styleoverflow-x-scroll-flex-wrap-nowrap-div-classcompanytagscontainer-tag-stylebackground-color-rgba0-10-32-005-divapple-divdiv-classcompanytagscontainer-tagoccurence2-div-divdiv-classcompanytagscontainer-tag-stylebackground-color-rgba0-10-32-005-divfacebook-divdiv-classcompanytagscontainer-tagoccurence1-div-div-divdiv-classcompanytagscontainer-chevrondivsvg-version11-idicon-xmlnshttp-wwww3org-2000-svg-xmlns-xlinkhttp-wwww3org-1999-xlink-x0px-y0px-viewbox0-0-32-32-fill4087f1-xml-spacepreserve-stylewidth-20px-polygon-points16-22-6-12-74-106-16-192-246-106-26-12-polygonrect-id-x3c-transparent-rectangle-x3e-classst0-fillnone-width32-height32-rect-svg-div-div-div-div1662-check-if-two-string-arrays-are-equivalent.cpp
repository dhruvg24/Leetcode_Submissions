class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         int word_idx1 = 0, word_idx2 = 0, ch_idx1 = 0, ch_idx2 =0;
        while(word_idx1<word1.size() && word_idx2<word2.size()){
            char ch1 = word1[word_idx1][ch_idx1];
            char ch2 = word2[word_idx2][ch_idx2];
            
            //if the character not same return false
            if(ch1!=ch2)
                return false;
            
            ch_idx1++; ch_idx2++;
            
            //if ch_idx1 == word.size() then word_idx1 increment and ch_idx1 reset to 0
            if(ch_idx1 >= word1[word_idx1].size()){
                word_idx1++;
                ch_idx1 = 0;
            }
            if(ch_idx2 >= word2[word_idx2].size()){
                word_idx2++;
                ch_idx2 = 0;
            }
        }
        return word_idx1 == word1.size() && word_idx2 == word2.size();
    }
};