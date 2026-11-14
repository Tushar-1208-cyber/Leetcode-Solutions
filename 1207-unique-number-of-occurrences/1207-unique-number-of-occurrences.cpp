class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;  // frequency counting

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        unordered_set<int> st;  // check krna ki koi frequency repeat to nhi ho rhi

        for(auto it = mp.begin(); it != mp.end(); it++){
            // Check kar rahe hain ki current frequency pehle se set mein present hai ya nahi.
            if(st.find(it->second) != st.end()){
                return false;    // Agar frequency repeat ho rahi hai, toh occurrences unique nahi hain.
            }
            else{
                st.insert(it->second);   // Agar frequency repeat nahi hai, toh use set mein store kar do.
            }
        }
        return true;    // Agar koi frequency repeat nahi hui, toh saari occurrences unique hain.
    }
};