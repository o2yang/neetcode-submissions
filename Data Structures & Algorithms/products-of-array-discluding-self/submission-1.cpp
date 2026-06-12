class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        vector<int> results;

        int production = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix.push_back(1);
                continue;
            }
            production *= nums[i-1];
            prefix.push_back(production);
        }
        production = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == (nums.size() - 1)) {
                suffix.push_back(1);
                continue;
            }
            production *= nums[i+1];
            suffix.push_back(production);
        }

        reverse(suffix.begin(), suffix.end());
        
        for (int i = 0; i < nums.size(); i++) {
            results.push_back(prefix[i] * suffix[i]);
        }

        return results;
    }
};
