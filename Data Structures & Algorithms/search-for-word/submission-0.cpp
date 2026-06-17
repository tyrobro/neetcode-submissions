class Solution {
public:
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(helper(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int r, int c, int i){
        int n = word.size();
        if(i == word.size()){
            return true;
        }

        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }

        board[r][c] = '#';

        bool ans = helper(board, word, r+1, c, i+1) || helper(board, word, r-1, c, i+1) || helper(board, word, r, c+1, i+1) || helper(board, word, r, c-1, i+1);
        board[r][c] = word[i];
        return ans;
    }
};
