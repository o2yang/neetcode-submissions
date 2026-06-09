class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stacks;

    for (int i = 0; i < tokens.size(); i++) {
        int input_num = -999;
        char input_op = ' ';
        try {
            input_num = stoi(tokens[i]);
        }
        catch (invalid_argument& e) {
            input_op = tokens[i][0];
        }
        if (input_num != -999) {
            stacks.push(input_num);
            cout << "push " << input_num << endl;
        }
        else {
            if (tokens[i][0] == '+') {
                int second_element = stacks.top();
                stacks.pop();
                int first_element = stacks.top();
                stacks.pop();
                stacks.push(first_element + second_element);
            }
            else if (tokens[i][0] == '-') {
                int second_element = stacks.top();
                stacks.pop();
                int first_element = stacks.top();
                stacks.pop();
                stacks.push(first_element - second_element);
            }
            else if (tokens[i][0] == '*') {
                int second_element = stacks.top();
                stacks.pop();
                int first_element = stacks.top();
                stacks.pop();
                stacks.push(first_element * second_element);
            }
            else {
                int second_element = stacks.top();
                stacks.pop();
                int first_element = stacks.top();
                stacks.pop();
                stacks.push(int(first_element / second_element));
            }
        }
    }
    return stacks.top();
    }
};
