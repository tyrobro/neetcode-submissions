class Solution
{
public:
  bool rowChecker(vector<vector<char>> &board)
  {
    unordered_map<char, int> rowCheck;
    for (int j = 0; j < 9; j++)
    {
      for (int i = 0; i < 9; i++)
      {
        if (board[i][j] == '.')
        {
          continue;
        }
        rowCheck[board[i][j]]++;
      }

      for (auto x : rowCheck)
      {
        if (x.second > 1)
        {
          return false;
        }
      }
      rowCheck.clear();
    }
    return true;
  }
  bool colChecker(vector<vector<char>> &board)
  {
    unordered_map<char, int> rowCheck;
    for (int j = 0; j < 9; j++)
    {
      for (int i = 0; i < 9; i++)
      {
        if (board[j][i] == '.')
        {
          continue;
        }
        rowCheck[board[j][i]]++;
      }

      for (auto x : rowCheck)
      {
        if (x.second > 1)
        {
          return false;
        }
      }
      rowCheck.clear();
    }
    return true;
  }
  bool gridChecker(vector<vector<char>> &board)
  {
    unordered_map<char, int> gridCheck;
    for (int m = 0; m < 9; m += 3)
    {
      for (int n = 0; n < 9; n += 3)
      {
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (board[m + i][n + j] == '.')
            {
              continue;
            }
            gridCheck[board[m + i][n + j]]++;
          }
        }
        for (auto x : gridCheck)
        {
          if (x.second > 1)
          {
            return false;
          }
        }
        gridCheck.clear();
      }
    }

    return true;
  }
  bool isValidSudoku(vector<vector<char>> &board)
  {
    return rowChecker(board) && colChecker(board) && gridChecker(board);
  }
};
