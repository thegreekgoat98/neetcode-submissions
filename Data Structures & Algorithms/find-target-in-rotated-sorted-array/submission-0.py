class Solution: 
    @staticmethod
    def findPivotIndex(nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1

        while l <= r:
            mid = l + (r-l)//2
            prev = (mid - 1 + n) % n
            nxt = (mid + 1) % n 

            if nums[mid] < nums[prev] and nums[mid] < nums[nxt]:
                return mid
            elif nums[mid] < nums[r]:
                r = mid - 1
            else:
                l = mid + 1
        
        return 0

    @staticmethod
    def BinarySearch(l: int, r: int, nums: List[int], target:int) -> int:
        while l <= r:
            mid = l + (r-l)//2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        
        return -1


    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)

        pivotIdx = Solution.findPivotIndex(nums)

        a = Solution.BinarySearch(0, pivotIdx-1, nums, target)
        b = Solution.BinarySearch(pivotIdx, n-1, nums, target)

        return max(a,b) # max because either the function return the index or -1, if index will be greater than -1


# https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=8    --  dope explanation