#include <ranges>
#include <vector>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

    vector<int> flat;
    for (auto &row : matrix)
        flat.insert(flat.end(), row.begin(), row.end());
    
    sort(flat.begin(), flat.end());

    return flat[k - 1];
    }
    // int L = 0;
    // int R = flat.size() - 1;
    // while (L <= R) {
    //     if (L == R) {
    //         return flat[i];
    //     }
    // }

    // return 0;

    // }
};