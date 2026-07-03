class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string& text1, string& text2)
    {
        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2);
        else
            return dp[i][j] = max(
                solve(i, j+1, text1, text2), 
                solve(i+1, j, text1, text2)
            );
        
        return 0;
    }
    ///////////////////////////////////////////////////////////
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();

        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, text1, text2);
    }
};

// recursive + memoization
// TC - O(m+n) - worst case
