class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int begin_ptr = 0;
        int global_longest = 0;

        for (int end_ptr = 0; end_ptr < s.length(); end_ptr++) {
            char c = s[end_ptr];

            if (last_seen.count(c)) {
                begin_ptr = max(begin_ptr, last_seen[c] + 1);
            }

            last_seen[c] = end_ptr;

            global_longest = max(global_longest, end_ptr - begin_ptr + 1);
        }

        return global_longest;
    }
};