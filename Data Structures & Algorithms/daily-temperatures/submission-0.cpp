class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> output(temperatures.size(), 0);
        stack<pair<int, int>> stacks;
        int t_now;

        for (int i = 0; i < temperatures.size(); i++) {
            t_now = temperatures[i];
            while (!stacks.empty() && t_now > stacks.top().first) {
                output[stacks.top().second] = i - stacks.top().second;
                stacks.pop();
            }
            stacks.push({t_now, i});
        }
        return output;
    }
};
