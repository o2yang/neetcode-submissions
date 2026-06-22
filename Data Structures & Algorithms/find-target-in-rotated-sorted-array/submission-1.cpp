class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int pivot;

        while (left < right) {
            // if (nums[left] <= nums[right]) {
            //     pivot = left;
            //     break;
            // }
            mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        pivot = left;

        cout << pivot << endl;

        if (target >= nums[pivot] && target <= nums[nums.size()-1]) {
           return binarySearch(nums, target, pivot, nums.size() - 1);
        }
        else {
            return binarySearch(nums, target, 0, pivot - 1);
        }
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
