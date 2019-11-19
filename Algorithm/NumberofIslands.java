/**
 * For every land, visit its neighbor land using DFS until there is no such land, mark every visited node as 0;
 * You found an island!
 * Time complexity: O(mn)
 */
class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        if (m == 0) {
            return 0;
        }
        int n = grid[0].length;
        int ans = 0;
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == '1') {
                    ++ans;
                    dfs(grid, x, y, n, m);
                }
            }
        }
        return ans;
    }

    private void dfs(char[][] grid, int x, int y, int n, int m) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0') {
            return;
        }
        grid[y][x] = '0';
        dfs(grid, x + 1, y, n, m);
        dfs(grid, x - 1, y, n, m);
        dfs(grid, x, y + 1, n, m);
        dfs(grid, x, y - 1, n, m);
    }
}