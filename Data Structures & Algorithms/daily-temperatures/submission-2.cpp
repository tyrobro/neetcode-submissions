class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
      int curr = temperatures[i];
      while (!st.empty() && curr > st.top().first)
      {
        auto duo = st.top();
        st.pop();
        ans[duo.second] = i - duo.second;
      }
      st.push({curr, i});
    }
    return ans;
  }
};