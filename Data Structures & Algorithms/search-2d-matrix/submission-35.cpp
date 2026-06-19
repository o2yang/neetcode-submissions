class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0) return false;

        int begin = 0;
        int end = matrix.size() * matrix[0].size() - 1;
        int middle, middle_row, middle_col;

        while (begin <= end) {
            middle = (begin + end) / 2;
            middle_row = middle / matrix[0].size();
            middle_col = middle % matrix[0].size();

            if (matrix[middle_row][middle_col] == target) return true;
            else if (matrix[middle_row][middle_col] < target) {
                begin = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
        return false;
    }
};
