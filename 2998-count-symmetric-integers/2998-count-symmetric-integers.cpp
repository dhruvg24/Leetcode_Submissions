class Solution {
public:
    bool isSym(int num){
        string str = to_string(num);
        int n= str.size();
        if(n%2!=0){
            return false;
        }
        int sum = 0, revSum = 0;
        for(int i = 0;i<n/2;i++){
            sum+=str[i] - '0', revSum += str[n -i-1] - '0';
        }
        return sum == revSum;
        
    }
    int countSymmetricIntegers(int low, int high) {
        int cntNum = 0;
        for(int i = low;i<=high;i++){
            if(isSym(i))
                cntNum++;
        }
        return cntNum;
    }
};