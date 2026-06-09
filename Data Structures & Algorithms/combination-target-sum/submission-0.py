class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self.res: List[List[int]] = []

        def solve(nums: List[int], target: int, currIdx: int, currList: List[int]):
            # base case
            if currIdx == len(nums):
                if target == 0:
                    self.res.append(currList.copy())
                return
                
            # pick
            if nums[currIdx] <= target:
                currList.append(nums[currIdx])
                solve(nums, target - nums[currIdx], currIdx, currList)
                currList.pop()
            
            # not pick
            solve(nums, target, currIdx + 1, currList)

        
        currList: List[int] = []
        solve(nums, target, 0, currList)

        return self.res

# target = 30, nums = [2]     --> will give worst case time complexity
# TC - O(n ^ (t/m))     where n is no of elements, t is target, m is minimum value of the list
# SC - O(number_of_solutions × average_solution_length)

