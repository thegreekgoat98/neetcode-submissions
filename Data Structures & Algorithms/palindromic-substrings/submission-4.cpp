class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        int cnt = 0;
        for(int L=1; L <= n; L++)
        {
            for(int i=0; i + L - 1 < n; ++i)
            {
                int j = L + i - 1;
                if(i == j) // one length substring
                    dp[i][j] = true;
                else if(i+1 == j) // two length substring
                    dp[i][j] = (s[i] == s[j]);
                else //generic
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);

                if(dp[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};
// TC - O(n^2)

// https://www.youtube.com/watch?v=jCK_y0h8VVE ----- watta explanation - gold
