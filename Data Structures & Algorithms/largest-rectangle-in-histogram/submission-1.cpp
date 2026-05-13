class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      int start = i;
      int curr = heights[i];
      while (!st.empty() && st.top().second > curr)
      {
        pair<int, int> front = st.top();
        int ind = front.first;
        int h = front.second;
        ans = max(ans, h * (i - ind));
        start = ind;
        st.pop();
      }
      st.push({start, curr});
    }

    while (!st.empty())
    {
      int ind = st.top().first;
      int height = st.top().second;

      ans = max(ans, height * (n - ind));
      st.pop();
    }

    return ans;
  }
};
