class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); i++) {
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(strs[i]);
        }

        vector<vector<string>> output;
        for (auto const& [key, val] : groups) {
            output.push_back(val);
        }

        return output;
    }
};