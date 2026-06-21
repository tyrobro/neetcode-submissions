class Solution {
    vector<vector<int>> guide = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int area = 0;

        for(int r = 0; r < ROWS; r++){
            for(int  c = 0; c < COLS; c++){
                if(grid[r][c] == 1){
                    area = max(area, helper(grid, r, c));
                }
            }
        }

        return area;
    }

    int helper(vector<vector<int>>& grid, int r, int c){
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});

        int ans = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for(auto x: guide){
                int nr = row + x[0];
                int nc = col + x[1];
                
                int n = grid.size();
                int m = grid[0].size();
                if(nr >=0 && nc >=0 && nr < n && nc < m && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    ans++;
                }
            }
        }

        return ans;
    }
};
