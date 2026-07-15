class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Put all rotten oranges into the queue
        // and count fresh oranges
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if(fresh == 0)
            return 0;

        int minutes = 0;

        // 4 directions
        vector<pair<int,int>> directions = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        // Multi-source BFS
        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                auto current = q.front();
                q.pop();

                int row = current.first;
                int col = current.second;

                for(auto dir : directions)
                {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if(newRow >= 0 && newRow < rows &&
                       newCol >= 0 && newCol < cols &&
                       grid[newRow][newCol] == 1)
                    {
                        grid[newRow][newCol] = 2;
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }

            if(!q.empty())
                minutes++;
        }

        if(fresh == 0)
            return minutes;

        return -1;
    }
};