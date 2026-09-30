class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long original = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                original += nums[i];
            else
                original -= nums[i];
        }

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                prefix[i + 1] = prefix[i] + nums[i];
            else
                prefix[i + 1] = prefix[i] - nums[i];
        }

        long long best = original;

        long long maxPrefix[2] = {
            prefix[0],
            LLONG_MIN
        };

        for(int i = 2; i <= n; i++) {
            int oldIndex = i - 2;

            maxPrefix[oldIndex % 2] =
                max(maxPrefix[oldIndex % 2], prefix[oldIndex]);

            int parity = i % 2;

            if(maxPrefix[parity] != LLONG_MIN) {
                long long change =
                    2 * (maxPrefix[parity] - prefix[i]);

                best = max(best, original + change);
            }
        }

        return best;
    }
};