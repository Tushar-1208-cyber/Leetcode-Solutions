class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        int sum = 0;

        for(int i=0;i<k;i++){
            sum += nums[i];
        }

        double avg = (double)sum / k;
        ans = avg;

        for(int i=k;i<nums.size();i++){
            sum = sum - nums[i-k] + nums[i];

            double avg = (double)sum / k;
            ans = max(ans, avg);
        }
        return ans;
    }
};