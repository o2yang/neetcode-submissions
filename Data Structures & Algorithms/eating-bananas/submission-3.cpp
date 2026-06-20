class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int max_value = *max_element(piles.begin(), piles.end());
        int begin_ptr = 1;
        int end_ptr = max_value;
        int min_eating_rate = 1000000001;

        while (begin_ptr <= end_ptr) {
            int middle_ptr = (begin_ptr + end_ptr) / 2;
            int eating_rate = middle_ptr;
            int hour_to_take = 0;
            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] % eating_rate > 0) hour_to_take ++;
                hour_to_take += (piles[i] / eating_rate);
            }

            if (hour_to_take <= h) {
                end_ptr = middle_ptr - 1;
                if (eating_rate < min_eating_rate)
                    min_eating_rate = eating_rate;
            }
            else {
                begin_ptr = middle_ptr + 1;
            }
        }

        return min_eating_rate;
    }
};
