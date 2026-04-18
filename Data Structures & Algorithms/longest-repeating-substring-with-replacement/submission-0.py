class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        mp = defaultdict(int)
        res = 0

        i, j = 0, 0

        while j < n:
            mp[s[j]] += 1

            while (j-i+1) - max(mp.values()) > k:
                mp[s[i]] -= 1
                i += 1

            res = max(res, j-i+1)
            j += 1

        return res
