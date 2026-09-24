class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }

                // Row Check
                if(row[i].find(board[i][j]) != row[i].end()){
                    return false;
                }
                row[i].insert(board[i][j]);
                
                // Column Check
                if(col[j].find(board[i][j]) != col[j].end()){
                    return false;
                }
                col[j].insert(board[i][j]);

                // 3x3 Matrix Check
                int boxIndex = (i / 3) * 3 + (j / 3);

                if(box[boxIndex].find(board[i][j]) != box[boxIndex].end()){
                    return false;
                }
                box[boxIndex].insert(board[i][j]);
            }
        }
        return true;
    }
};