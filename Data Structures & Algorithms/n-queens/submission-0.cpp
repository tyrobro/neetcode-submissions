class Solution {
public:
    vector<string> board;
    vector<bool> col, posD, negD;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);
        posD.resize(2*n, false);
        negD.resize(2*n, false);
        board.resize(n, string(n, '.'));

        helper(0, n);
        return ans;
    }

    void helper(int r, int n){
        if(r == n){
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if(col[c] || posD[r+c] || negD[r-c+n]){
                continue;
            }

            col[c] = true;
            posD[r+c] = true;
            negD[r - c + n] = true;
            board[r][c] = 'Q';

            helper(r+1, n);

            col[c] = false;
            posD[r+c] = false;
            negD[r-c+n] = false;
            board[r][c] = '.';
        }
    }
};
