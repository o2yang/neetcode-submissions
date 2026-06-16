class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int begin_ptr = i + 1;
            int end_ptr = nums.size()-1;
            int sum;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (begin_ptr < end_ptr) {
                sum = nums[begin_ptr] + nums[end_ptr];
                if (sum == target) {
                    output.push_back({-target, nums[begin_ptr], nums[end_ptr]});
                    end_ptr --;
                    begin_ptr ++;
                    while (begin_ptr < end_ptr && nums[begin_ptr] == nums[begin_ptr-1]) {
                        begin_ptr ++;
                    }
                }
                else if (sum > target) end_ptr --;
                else begin_ptr ++;
            }
        }

        return output;
    }
};
