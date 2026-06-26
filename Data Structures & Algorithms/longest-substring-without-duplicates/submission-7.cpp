class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin_ptr = 0;
        int end_ptr = 0;
        unordered_map<char, int> appeared_char;
        int global_longest = 0;
        int local_longest = 0;

        if (s.empty()) return 0;
        // if (s.length() == 1) return 1;

        while (end_ptr < s.length()) {
            if (!appeared_char.count(s[end_ptr])) {
                appeared_char.insert({s[end_ptr], end_ptr});
                local_longest = end_ptr - begin_ptr + 1;
                if (local_longest > global_longest) global_longest = local_longest;
            }
            else {
                local_longest = end_ptr - begin_ptr;
                if (local_longest > global_longest) global_longest = local_longest;
                int temp_idx = appeared_char.find(s[end_ptr])->second;
                
                for (int i = begin_ptr; i <= temp_idx; i++) {
                    appeared_char.erase(s[i]);
                }
                begin_ptr = temp_idx + 1;
                appeared_char.insert({s[end_ptr], end_ptr});
            }
            
            end_ptr ++;
        }
        return global_longest;
    }
};
