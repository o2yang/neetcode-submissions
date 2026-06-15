class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> position_time;

        for (int i = 0; i < position.size(); i++) {
            position_time.push_back({position[i], (float)(static_cast<float>(target - position[i]) / speed[i])});
            cout << (float)(static_cast<float>(target - position[i]) / speed[i]) << endl;
        }

        sort(position_time.begin(), position_time.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        vector<float> fleet_amounts;
        for (const auto& pos : position_time) {
            if (fleet_amounts.empty()) {
                fleet_amounts.push_back(pos.second);
            }
            if(pos.second > fleet_amounts.back()) fleet_amounts.push_back(pos.second);

            // cout << fleet_amounts.back() << endl;
            // for (int i = 0; i < fleet_amounts.size(); i++) {
            //     cout << fleet_amounts[i] << " ";
            // }
            // cout << endl;
        }

        return fleet_amounts.size();
    }
};
