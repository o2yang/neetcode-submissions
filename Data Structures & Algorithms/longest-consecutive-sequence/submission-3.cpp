class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        int local_longest_seq = 1;
        int global_longest_seq = 1;

        if (nums.size() == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            hash_set.insert(nums[i]);
        }

        for (const auto& number : hash_set) {
            local_longest_seq = 1;
            if (!hash_set.count(number - 1)) {
                int number_now = number;
                while (hash_set.count(number_now + 1)) {
                    local_longest_seq ++;
                    number_now ++;
                }
                if (local_longest_seq > global_longest_seq) global_longest_seq = local_longest_seq;
            }
        }
        return global_longest_seq;
    }
};
