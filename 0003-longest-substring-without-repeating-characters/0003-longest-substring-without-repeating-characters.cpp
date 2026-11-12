class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;

        unordered_set<char> st;

        for(int right = 0; right < n; right++) {

            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int ans = 0;
    
//         for(int i=0;i<s.size();i++){
//             unordered_set<char> st;

//             for(int j=i;j<s.size();j++){
//                 if(st.find(s[j]) != st.end()){
//                     break;
//                 }
//                 else{
//                     st.insert(s[j]);
//                     ans = max(ans, j - i + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };