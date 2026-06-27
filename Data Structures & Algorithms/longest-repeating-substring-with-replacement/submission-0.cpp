class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_count;
        int max_freq_char = 0;
        int res = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char_count[s[right]] ++;

            // we only need to comapare the new incremented valu to the max value
            max_freq_char = max(max_freq_char, char_count[s[right]]);

            int sliding_window_size = right - left + 1;
            while (sliding_window_size - max_freq_char > k) {
                char_count[s[left]] --;
                left ++;
                sliding_window_size = right - left + 1;
            }

            res = max(res, sliding_window_size);
        }
        return res;
    }
};
