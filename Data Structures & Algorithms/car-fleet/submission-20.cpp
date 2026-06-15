class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> position_time;

        for (int i = 0; i < position.size(); i++) {
            position_time.push_back({position[i], (static_cast<double>(target - position[i]) / speed[i])});
        }

        sort(position_time.begin(), position_time.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        vector<double> fleet_amounts;
        for (const auto& pos : position_time) {
            if (fleet_amounts.empty() || pos.second > fleet_amounts.back()) {
                fleet_amounts.push_back(pos.second);
            }
        }

        return fleet_amounts.size();
    }
};
