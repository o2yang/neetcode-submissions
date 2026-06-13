class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row(9);
        vector<unordered_map<char, int>> col(9);
        vector<unordered_map<char, int>> sqaure(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (!row[i].count(board[i][j])) row[i].insert({board[i][j], 1});
                else return false;

                if(!col[j].count(board[i][j])) col[j].insert({board[i][j], 1});
                else return false;

                if(!sqaure[(i/3) * 3 + (j/3)].count(board[i][j])) sqaure[(i/3) * 3 + (j/3)].insert({board[i][j], 1});
                else return false;
            }
        }
        return true;
    }
};
