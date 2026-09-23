class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // child ko ascending order me arrange kr diya hai 
        sort(s.begin(), s.end());  // cookies ko ascending order me arrange kr diya hai 
        
        int i = 0;  // child pointer 
        int j = 0;  // cookie pointer 

        while(i < g.size() && j < s.size()){  // koi child ya cookies remaining hai 
            if(s[j] >= g[i]){  // current cookies child ki greed satisfy kr skti ?
                i++;  // dono ko next move kr diya 
                j++;
            }
            else{
                j++;  // agar cookie choti hai to cookies pointer aage jaega 
            }
        }
        return i;  // satisfied children ki count hai kyunki isko hum i++ krte hai upar jo satisfy hote hai uske basis per 
    }
};