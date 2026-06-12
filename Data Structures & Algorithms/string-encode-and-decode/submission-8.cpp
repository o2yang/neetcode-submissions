class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        if (strs.size() == 0) return "";
        for (auto& s : strs) {
            encoded_string.append(to_string(s.size()));
            encoded_string.append(" ");
            encoded_string.append(s);
        }
        // cout << encoded_string << endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int length = 0;
        if (s.size() == 0) return {};

        int i = 0, j = i + 1;
        while (i < s.size()) {
            if (s[j] == ' ') {
                length = length * 10 + int(s[i] - '0');
                // cout << length << endl;
                // cout << s.substr(j+1, length) << endl;
                decoded_string.push_back(s.substr(j+1, length));
                i = i + length + 2;
                j = i + 1;
                length = 0;
            }
            else {
                length = length * 10 + int(s[i] - '0');
                i++;
                j++;
            }
        }
        return decoded_string;
    }
};
