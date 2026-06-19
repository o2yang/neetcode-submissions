class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* brute force in time of O(m*n) */

        vector<int> flatten_matrix;

        if (matrix.size() == 0) return false;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                flatten_matrix.push_back(matrix[i][j]);
            }
        }
        int begin = 0;
        int end = flatten_matrix.size() - 1;
        int middle = (begin + end) / 2;

        while (begin <= end) {
            if (target == flatten_matrix[middle]) return true;
            else if (flatten_matrix[middle] < target) {
                begin = middle + 1;
                middle = (begin + end) / 2;
            }
            else {
                end = middle - 1;
                middle = (begin + end) / 2;
            }
        }
        return false;
    }
};
