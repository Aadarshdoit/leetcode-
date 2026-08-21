class Solution {
public:
    int findGCD(vector<int>& nums) {

        int smallest = nums[0];
        int largest = nums[0];

        // Find smallest and largest
        for (int i = 0; i < nums.size(); i++) {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }

        // Euclidean algorithm
        while (smallest > 0) {
            int remainder = largest % smallest;

            largest = smallest;
            smallest = remainder;
        }

        return largest;
    }
};