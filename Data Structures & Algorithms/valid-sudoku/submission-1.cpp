class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int square[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int value = board[i][j] - '1'; // 0~8
                value = 1 << value;

                if ((row[i] & value) || (col[j] & value) || (square[(i/3)*3+(j/3)] & value)) return false;

                row[i] |= value;
                col[j] |= value;
                square[(i/3)*3+(j/3)] |= value;
            }
        }
        return true;
    }
};
