class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // using pq
        // total battery charge store in sum
        // now for n comp. -> sum/n power for simulataneous operations
        long long totalChargePresent = 0;
        for(auto &it: batteries){
            totalChargePresent += it;
        }
        priority_queue<int> pq;
        for(auto &it: batteries){
            pq.push(it);
        }

        // until we have a battery with charge remaining > sum/n then it can be used for a computer as long as simulataneous op. is reqd for it and need to check for remaining ones
        while(pq.top()>totalChargePresent/n){
            // going n times
            // each req O(log m)
            // T.C. - O(nlogm)
            totalChargePresent-=pq.top();
            pq.pop();
            // here need to decrement n as well
            // since single comp. can go as long as a battery has charge totalCharge/n
            n--;
        }

        return totalChargePresent/n;


    }
};