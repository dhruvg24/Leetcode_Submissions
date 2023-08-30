class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int cur = 0;cur<=num;cur++){
            int curNum = 0, tmp = cur;
            while(tmp>0){
                curNum = curNum * 10 + tmp%10;
                tmp/=10;
            }
            if(cur + curNum == num){
                return true;
            }

        }
        return false;
    }
};