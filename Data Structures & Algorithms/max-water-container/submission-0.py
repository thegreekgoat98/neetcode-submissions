class Solution:
    def maxArea(self, arr: List[int]) -> int:
        n = len(arr)

        i = 0
        j = n-1

        maxWater = 0
        while i < j:
            height = min(arr[i], arr[j])
            width = j - i

            area = height * width
            maxWater = max(maxWater, area)

            # move
            if arr[i] < arr[j]:
                i += 1
            else:
                j -= 1

        return maxWater