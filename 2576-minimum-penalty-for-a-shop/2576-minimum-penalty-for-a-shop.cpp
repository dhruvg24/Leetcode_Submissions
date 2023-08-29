class Solution {
public:
    int bestClosingTime(string customers) {
        // shop open + no cust , shop closed + cust -> penalty++
        // earliest hour to minimize penalty?

        int bestTime = -1, n = customers.size(), curPenalty = 0, maxi =0;
        // we will keep a track of bestTime when maxScore achieved. 
        for(int i = 0;i<n;i++){
            char c = customers[i];
            if(c == 'Y'){
                curPenalty++;
                // if shop wd hav been closed -> penalty++
            }
            else if(c == 'N'){
                // none is visiting 
                curPenalty--;
                // if shop open -> results in penalty
            }
            if(curPenalty>maxi){
                maxi = curPenalty;
                bestTime = i;
            }
        }
        return 1+bestTime;
        // 0 indexed
        
    }
};