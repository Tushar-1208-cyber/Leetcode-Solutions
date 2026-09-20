class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        int currentRow = 0;
        bool goingDown = true;

        if(numRows == 1){
            return s;
        }

        for(int i=0;i<s.size();i++){
            ans[currentRow] = ans[currentRow] + s[i];

            if(currentRow == 0){
                goingDown = true;
            }

            if(currentRow == numRows - 1){
                goingDown = false;
            }

            if(goingDown){
                currentRow++;
            }
            else{
                currentRow--;
            }
        }
        string result = "";

        for (int i = 0; i < numRows; i++) {
            result = result + ans[i];
        }

        return result;
    }
};