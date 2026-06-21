class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        int min_element = 1001;

        while (left <= right) {
            middle = (left + right) / 2;
            cout << left << " " << middle << " " << right << endl;

            if (nums[middle] < nums[right]) {
                right = middle - 1;
                if (nums[middle] < nums[left]) {
                    if (nums[middle] < min_element) min_element = nums[middle];
                    cout << "case 1-1: " << min_element << endl;
                }
                else {
                    if (nums[left] < min_element) min_element = nums[left];
                    cout << "case 1-2: " << min_element << endl;
                }
            }
            else {
                left = middle + 1;
                if (nums[middle] < nums[right]) {
                    if (nums[middle] < min_element) min_element = nums[middle];
                    cout << "case 2-1: " << min_element << endl;
                }
                else {
                    if (nums[right] < min_element) min_element = nums[right];
                    cout << "case 2-2: " << min_element << endl;
                }
            }
        }
        return min_element;
    }
};
