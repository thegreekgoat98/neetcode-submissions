class Solution {
public:
    vector<vector<int>>dp;
    bool isPalindrome(int i, int j, string&s)
    {   
        if(i >= j)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = isPalindrome(i + 1, j - 1, s);
        
        return dp[i][j] = false;
    }
    ///////////////////////////////////
    int countSubstrings(string s) 
    {
        int n=s.size();

        dp.resize(n, vector<int>(n,-1));
        // dp[i][j] = -1 (not yet solved)
        // dp[i][j] = 0 not palindrome from idx i to j(inclusive)
        // dp[i][j] = 1 palindrome from idx i to j(inclusive)
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
                if(isPalindrome(i, j, s))
                    cnt++;
        }

        return cnt;
    }
};

// Bruteforce - recursive
// TC - O(n^3)
// SC - O(1)
