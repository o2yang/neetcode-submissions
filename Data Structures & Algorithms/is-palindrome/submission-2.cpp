class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) {
            return !(isalpha(c) || isdigit(int(c)));
        });
        int len = s.length();
        if (len == 1) return true;
        for (int i = 0, j = len-1; i < len/2; i++, j--) {
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
