# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxSum = float('-inf')
        def solve(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            l: int = solve(node.left)
            r: int = solve(node.right)

            # 3 cases arise

            # 1. got answer below(completed the path below)
            got_ans_below: int = l + r + node.val

            # 2. will select either left or write with root 
            select_either_left_or_right: int = node.val + max(l, r)

            # 3. none of the left or right sum is better, so will only select the root
            only_root: int = node.val

            # will compare all the three values calculated
            self.maxSum = max(self.maxSum, got_ans_below, select_either_left_or_right, only_root)

            # but will return only 2nd and 3rd case, because in first case, we already got answer below without going upwards
            return max(select_either_left_or_right, only_root)
        
        solve(root)

        return self.maxSum


# https://www.youtube.com/watch?v=Op6YFcs8R9M - beautiful beautiful brilliant 