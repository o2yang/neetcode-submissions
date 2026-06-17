class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left_ptr = 0;
        int right_ptr = heights.size() - 1;
        int max_amount = -1;
        
        
        while (left_ptr < right_ptr) {
            int area = min(heights[left_ptr], heights[right_ptr]) * (right_ptr - left_ptr);
            if (area > max_amount) {
                max_amount = area;
            }
            if (heights[left_ptr] < heights[right_ptr]) left_ptr ++;
            else right_ptr --;
        }
        return max_amount;
    }
};
