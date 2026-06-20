class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;

        for(int i = 0;i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]=='1'){
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> q;
        grid[i][j] = '0';
        q.push({i, j});
        int n  = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first, c = node.second;

            for(int row = 0; row < 4; row++){
                int nr = r + directions[row][0];
                int nc = c + directions[row][1];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
