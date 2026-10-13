class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> squArr(n); 

        for(int i=0;i<n;i++){
            squArr[i] = 1LL * nums[i] * nums[i];
        } 

        sort(squArr.begin(), squArr.end());

        long long m = squArr.size();
        long long high = m-1;
        long long low = 0;
        long long score = 0;

        while(low < high){
            score += squArr[high];
            score -= squArr[low];
            high--;
            low++; 
        }  
        if(low == high){   // bahar isliye kyunki loop ke andar 2 elements process krte hai 
            score += squArr[low];  
        }
        return score;
    }
};