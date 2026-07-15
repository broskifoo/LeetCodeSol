class Solution {
public:
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || i >= rows ||
           j < 0 || j >= cols ||
           grid[i][j] == 0)
        {
            return 0;
        }

        grid[i][j] = 0;

        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};