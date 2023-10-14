class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = 0, n = hours.size();
        for(int i = 0;i<n;i++){
            int curLen = 0;
            for(int j = i;j<n;j++){
                if(hours[j]>8){
                    curLen++;
                }
                else{
                    curLen--;
                }
                if(curLen>0){
                    len = max(len, j-i+1);
                }
            }
        }
        return len;
    }
};
