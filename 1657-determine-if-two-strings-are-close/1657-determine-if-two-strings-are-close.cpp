class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()){  // dono strings ki length same hai ya nahi.
            return false;
        }

        unordered_set<char> st1;
        unordered_set<char> st2;

        for(int i = 0; i < word1.size(); i++){
            st1.insert(word1[i]);
            st2.insert(word2[i]);
        }

        if(st1 != st2){   // dono strings mein same distinct characters hain ya nahi.
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0;i<word1.size();i++){
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        // Sorting isliye kar rahe hain taaki dono strings ki frequency values ka order same ho jaaye aur hum unhe easily compare kar sakein.
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        if(freq1 == freq2){
            return true;
        }
        else{
            return false;
        }
    }
};