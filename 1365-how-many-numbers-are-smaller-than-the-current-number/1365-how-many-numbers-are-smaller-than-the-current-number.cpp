class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int freq[101] = {0};

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(int i=1;i<=100;i++){
            freq[i] = freq[i] + freq[i-1];
        }

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(freq[nums[i] - 1]); // nums[i]-1 gives the previous value, so freq stores the count of numbers smaller than nums[i]
            }
        }
        return ans;
    }
};