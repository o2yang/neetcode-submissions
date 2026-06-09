class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<vector<int>> freq_bucket(nums.size() + 1); // specify only the row amounts
        vector<int> _output;

        for (int i : nums) {
            counts[i]++;
        }

        for (auto& number : counts) {
            freq_bucket[number.second].push_back(number.first);
        }

        for (int freq = nums.size(); freq > 0; freq--) {
            for (int n : freq_bucket[freq]) {
                _output.push_back(n);
                if (_output.size() == k) return _output;
            }
        }
        return _output;
    }
};
