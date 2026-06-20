class Solution {
public:
    bool isPalindrome(string &s, int i, int j)
    {
        if(i >= j)
            return true;

        if(s[i] == s[j])
            return isPalindrome(s, i+1, j-1);
        return false;
    }
    /////////////////////////////////////
    string longestPalindrome(string s) 
    {
        int n=s.size();

        int startIdx = 0;
        int maxLen = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                if(isPalindrome(s, i, j))
                {
                    if(j-i+1 > maxLen)
                    {
                        startIdx = i;
                        maxLen = max(maxLen, j-i+1);
                    }
                }
            }
        }
        cout<<startIdx<<maxLen;
        return s.substr(startIdx, maxLen);
    }
};

//recursive
// TC - O(n^3)
