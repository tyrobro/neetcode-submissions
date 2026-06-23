class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = 0;
        int left = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    left++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(left > 0 && !q.empty()){
            int len = q.size();
            for(int i  =0; i < len; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& dir: directions){
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        left--;
                    }
                }
            }
            time++;
        }

        return left == 0 ? time : -1;

    }
};
