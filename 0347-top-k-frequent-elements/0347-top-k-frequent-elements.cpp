class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){  // har elemet ko hashmap me count kr rhe hai
            mp[nums[i]]++;
        }

        // aab hashmap ko sort krenge hum but we cannot directly sort an unordered map
        // isliye ek vector pair bnaya hai jisme har element ek pair me store ho jaye 
        // pair means first -> number and second -> frequency 
        vector<pair<int,int>> v;  
        for(auto it=mp.begin(); it != mp.end(); it++){  // traversing the hashmap and it means hasmap entry
            v.push_back({it->first, it->second});   // pair ko vector me dal diya 
        }

        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){  // yha hume frequency ke basis per sort krna hai 
            return a.second > b.second;  // frequency zyada vo phle 
        });

        vector<int> ans;
        
        for(int i=0;i<k;i++){  // humein top k elements chahiye ans vector me 
            ans.push_back(v[i].first);
        }

        return ans;
    }
};