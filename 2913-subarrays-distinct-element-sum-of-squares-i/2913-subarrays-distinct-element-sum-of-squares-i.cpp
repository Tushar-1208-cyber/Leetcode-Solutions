class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;    // only unique elements store krega
        int ans = 0;  // Sabhi subarrays ke squared counts ka total

        for(int i=0;i<n;i++){   // i will tell ki subarray kha se start hoga
            st.clear();   // har bar naye index ke liye set ko empty krna pdega 
            for(int j=i;j<n;j++){    // j btata hai ki subarray ka ending index kha hoga
                st.insert(nums[j]);  // Current element ko set mein insert karna and duplicates store nhi honge
                ans += st.size() * st.size();   // st.size() unique elements ki count deta hai count ka square ans me add krta hai
            }
        }
        return ans;
    }
};