class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin_ptr = 0;
        int end_ptr = matrix.size() - 1;
        int middle_ptr;

        // First round => find the target_row
        while (begin_ptr <= end_ptr) {
            middle_ptr = (begin_ptr + end_ptr) / 2;
            if (matrix[middle_ptr][0] == target) {
                return true;
            }
            else if (matrix[middle_ptr][0] < target) {
                if (begin_ptr != end_ptr) begin_ptr = middle_ptr + 1;
            }
            else {
                if (begin_ptr != end_ptr) end_ptr = middle_ptr - 1;
            }
            // the last round, we need to check if the first element in the target_row is bigger than the target
            // if it is bigger, which means that the smallest value in the target_row is bigger than the target
            // so that every coming element is indeed more larger, so we decrement the target_row by 1
            if (end_ptr == begin_ptr) {
                if ((matrix[begin_ptr][0] > target) && begin_ptr != 0) begin_ptr--;
                break;
            }
        }
        // Second round => find the target according to the target_row
        int target_row = begin_ptr;
        begin_ptr = 0;
        end_ptr = matrix[0].size() - 1;
        while (begin_ptr <= end_ptr) {
            middle_ptr = (begin_ptr + end_ptr) / 2;
            if (matrix[target_row][middle_ptr] == target) {
                return true;
            }
            else if (matrix[target_row][middle_ptr] < target) {
                begin_ptr = middle_ptr + 1;
            }
            else {
                end_ptr = middle_ptr - 1;
            }
        }
        return false;
    }
};
