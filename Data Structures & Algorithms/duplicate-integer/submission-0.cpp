class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int hasDuplicate = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= i-1; j++) {
                if (nums[i] == nums[j]) {
                    hasDuplicate = 1;
                    break;
                }
            }
        }
        if (hasDuplicate) return true;
        else return false;
    }
};