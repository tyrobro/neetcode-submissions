class Solution {
public:

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c] = true;
        int n = heights.size();
        int m = heights[0].size();

        for(auto [dr, dc] : directions){
            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nr < n && nc >=0 && nc < m && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                dfs(nr, nc, ocean, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<bool>> pac(R, vector<bool>(C, false));
        vector<vector<bool>> atl(R, vector<bool>(C, false));
        
        for(int c = 0; c < C; c++){
            dfs(0, c, pac, heights);
            dfs(R-1, c, atl, heights);
        }
        for(int r = 0; r < R; r++){
            dfs(r, 0, pac, heights);
            dfs(r, C-1, atl, heights);
        }

        vector<vector<int>> ans;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(pac[r][c] && atl[r][c]){
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }
};
