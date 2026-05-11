class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
      int curr = temperatures[i];
      for (int j = i + 1; j < n; j++)
      {
        if (temperatures[j] > curr)
        {
          ans[i] = (j - i);
          break;
        }
      }
    }
    return ans;
  }
};
