#include <set>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            long val = nums[i];
            
            auto it = window.lower_bound(val - valueDiff);
            
            if (it != window.end() && *it <= val + valueDiff) {
                return true;
            }
            
            window.insert(val);
            
            if (window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};
