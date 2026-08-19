class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> rows;

        // Store reserved seats for each row
        for (auto &seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[row, reserved] : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Check seats 2-5
            for (int j = 2; j <= 5; j++) {
                if (reserved.count(j)) {
                    left = false;
                    break;
                }
            }

            // Check seats 4-7
            for (int j = 4; j <= 7; j++) {
                if (reserved.count(j)) {
                    middle = false;
                    break;
                }
            }

            // Check seats 6-9
            for (int j = 6; j <= 9; j++) {
                if (reserved.count(j)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};