class Solution {
public:
    bool check(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == target)
                continue;

            bool possible = false;

            for(int j = 0; j < nums.size(); j++) {
                if(i == j)
                    continue;

                int result = nums[i] - nums[j];

                if(abs(result) % 2 == target) {
                    possible = true;
                    break;
                }
            }

            if(!possible)
                return false;
        }

        return true;
    }

    bool uniformArray(vector<int>& nums) {
        return check(nums, 0) || check(nums, 1);
    }
};