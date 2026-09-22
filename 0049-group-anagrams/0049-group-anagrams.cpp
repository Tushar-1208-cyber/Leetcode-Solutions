class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;  // ek string ke against ek vector string store krna [key,value]

        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());

            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it=mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second); // it->first means key and it->second means value 
        }

        return ans;
    }
};