class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]

        def isValid(i, j):
            return (i >= 0 and j >=0 and i < n and j < m)

        def dfs(i, j):
            grid[i][j] = "0"

            for dir in dirs:
                ni = i + dir[0]
                nj = j + dir[1]

                if isValid(ni, nj) and grid[ni][nj] == "1":
                    dfs(ni, nj)

            
        cnt = 0
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == "1":
                    dfs(i, j)
                    cnt += 1
        
        return cnt
