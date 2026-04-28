/*
 * String LCS (Longest Common Subsequence)
 * Time: O(N*M)
 * Use: Finding the longest sequence present in both strings
 */
struct LCS {
    int n, m;
    string a, b;
    vector<vector<int>> dp;
    LCS(string &_a, string &_b) : a(_a), b(_b) {
        n = sz(a); m = sz(b);
        dp.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    string find_LCS() {
        string res = "";
        int i = 0, j = 0, len = dp[0][0];
        while (len > 0) {
            if (a[i] == b[j]) {
                res.push_back(a[i]);
                i++; j++; len--;
            } else if (dp[i+1][j] >= dp[i][j+1]) i++;
            else j++;
        }
        return res;
    }
};
