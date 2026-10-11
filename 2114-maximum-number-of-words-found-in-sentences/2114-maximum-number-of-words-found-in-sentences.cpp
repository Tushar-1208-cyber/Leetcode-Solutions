class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();  // Total sentences
        int maxWords = 0;          // Maximum words wala sentence

        for (int i = 0; i < n; i++) {
            int spaceCount = 0;  // Current sentence ke spaces

            for (int j = 0; j < sentences[i].size(); j++) {
                // Har character check karo
                if (sentences[i][j] == ' ') {
                    spaceCount++;  // Space mila
                }
            }

            // Words = spaces + 1
            int words = spaceCount + 1;

            // Maximum words update karo
            if (words > maxWords) {
                maxWords = words;
            }
        }

        // Maximum words return karo
        return maxWords;
    }
};