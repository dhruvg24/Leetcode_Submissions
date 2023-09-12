class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> frq;
        int minDel = 0;
        unordered_set<int>st;
        for(auto it: s){
            frq[it]++;
        }
        for(auto it: frq){
            int curF = it.second;
            while(curF>0 && st.find(curF)!=st.end()){
                // existing freq del it insert fresh
                curF--;
                minDel++;
            }
            st.insert(curF);
        }
        return minDel;
    }
};