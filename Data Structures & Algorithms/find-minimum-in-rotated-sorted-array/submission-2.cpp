class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        int min_element = 1001;

        while (left <= right) {
            middle = (left + right) / 2;

            if (nums[middle] < nums[right]) {
                right = middle - 1;
                if (nums[middle] < nums[left]) {
                    if (nums[middle] < min_element) min_element = nums[middle];
                }
                else {
                    if (nums[left] < min_element) min_element = nums[left];
                }
            }
            else {
                left = middle + 1;
                if (nums[middle] < nums[right]) {
                    if (nums[middle] < min_element) min_element = nums[middle];
                }
                else {
                    if (nums[right] < min_element) min_element = nums[right];
                }
            }
        }
        return min_element;
    }
};
