class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int digit;   // current position ke liye choose ki gyi digit store krenge

        // ek digit ki max val 9 ho skti hai if num=3 then max sum = 27 if sum = 30 given then 3 digits ka total 30 nhi ho skta so return "" 
        if(sum > 9*num){
            return "";
        }

        // Build exactly 'num' digits
        for(int i=0;i<num;i++){
            digit = min(9, sum);  // min dono me se choti val return krta hai 
            ans.push_back(digit + '0');   // Convert the integer digit into a character and append it
            sum -= digit;   // updating the remaining sum
        }
        return ans;
    }
};