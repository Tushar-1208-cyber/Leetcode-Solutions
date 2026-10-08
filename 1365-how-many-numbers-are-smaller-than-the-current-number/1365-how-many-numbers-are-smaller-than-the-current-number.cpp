class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int count = 0;  // for counting kitne numbers chote hai usse 

            for(int j=0;j<n;j++){  // 
                if(nums[j] < nums[i]){  // kya j wala number, current i wale number se choota hai checking 
                    count++;  // agar hai to ++ kr do count me 
                }
            }
            ans.push_back(count);  // yha ans me count ki loop ke sath value bhi push krte jao 
        }
        return ans;
    }
};