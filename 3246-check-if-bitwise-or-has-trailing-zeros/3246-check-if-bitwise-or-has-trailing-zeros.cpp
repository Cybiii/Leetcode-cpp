class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int hasTwoEvenNumbers = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) == 0)
                hasTwoEvenNumbers++;
            if (hasTwoEvenNumbers == 2)
                break;
        }
        if (hasTwoEvenNumbers == 2)
            return true;
        else
            return false;
    }
};