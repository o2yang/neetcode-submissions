class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_frequency_map;
        vector<int> output;
        

        for (int i = 0; i < nums.size(); i++) {
            if (num_frequency_map.count(nums[i])) {
                num_frequency_map[nums[i]] += 1;
            }
            else {
                num_frequency_map.insert({nums[i], 1});
            }
        }

        // copy the map value to vector, because the map is a hash table which cannot be sorted directly
        vector<pair<int, int>> sortedVector(num_frequency_map.begin(), num_frequency_map.end());
        
        sort(sortedVector.begin(), sortedVector.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++) {
            output.push_back(sortedVector[i].first);
            // cout << sortedVector[i].first << sortedVector[i].second << endl;
        }
        return output;
    }
};
