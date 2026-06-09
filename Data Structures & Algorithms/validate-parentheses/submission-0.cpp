class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        map<char, char> parentheses = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (parentheses.count(c)) {
                if (!stack.empty() && stack.top() == parentheses[c]) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
