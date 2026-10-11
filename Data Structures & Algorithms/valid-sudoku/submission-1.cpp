class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> box(9,vector<bool>(9,false));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int val = board[i][j] -'1';
                if(row[i][val]) return false;
                else row[i][val]=true;

                if(col[j][val]) return false;
                else col[j][val]=true;
                
                int boxIdx= (i/3) * 3 + (j/3);
                if(box[boxIdx][val]) return false;
                else box[boxIdx][val]=true;

            }
        }
        return true;
    }
};
