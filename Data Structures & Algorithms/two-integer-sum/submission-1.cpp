class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++) {
            hash_table[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash_table.count(target-nums[i]) && hash_table[target-nums[i]] != i) {
                return {min(i, hash_table[target-nums[i]]), max(i, hash_table[target-nums[i]])};
            }
        }
        return {};
    }
};
