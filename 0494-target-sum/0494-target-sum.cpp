class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int numberofways = 0;
        backtrack(0, 0, nums, target, numberofways);
        return numberofways;
    }

private:
    void backtrack(int index, int current_sum, const vector<int>& nums, int target, int& numberofways) {
        if (index == nums.size()) {
            if (current_sum == target) numberofways++;
            return;
        }
        backtrack(index + 1, current_sum + nums[index], nums, target, numberofways);
        backtrack(index + 1, current_sum - nums[index], nums, target, numberofways);
    }
};
