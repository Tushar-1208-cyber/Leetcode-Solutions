class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(15, 0);

        vector<vector<int>> groups;
        groups.push_back(nums);

        for(int bit = 14; bit >= 0; bit--) {

            int prefix = 0;

            for(int j = 0; j < groups.size(); j++) {

                vector<int> ones;
                vector<int> zeros;

                for(int k = 0; k < groups[j].size(); k++) {

                    if(groups[j][k] & (1 << bit)) {
                        ones.push_back(groups[j][k]);
                    }
                    else {
                        zeros.push_back(groups[j][k]);
                    }
                }

                prefix += ones.size();

                if(ones.size() != groups[j].size()) {

                    if(ones.size() > 0) {
                        groups[j] = ones;

                        groups.insert(
                            groups.begin() + j + 1,
                            zeros
                        );
                    }

                    break;
                }
            }

            ans[14 - bit] = prefix;
        }

        return ans;
    }
};