class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<2*n;i++){
            ans.push_back(nums[i % n]); // i % n mtlb n 3 ke baad index ko vapas 0 per la rha hai 
        }
        return ans;
    }
};