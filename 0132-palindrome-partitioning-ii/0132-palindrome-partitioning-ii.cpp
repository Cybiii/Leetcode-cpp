class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) {
                        isPalin[i][j] = true;
                    } else {
                        isPalin[i][j] = isPalin[i + 1][j - 1];
                    }
                }
            }
        }
        
        vector<int> dp(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPalin[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};