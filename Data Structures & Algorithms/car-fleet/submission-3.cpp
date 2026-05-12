class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int cars = position.size();
    if (cars == 0)
      return 0;

    vector<pair<int, int>> rank;
    for (int i = 0; i < cars; i++)
    {
      rank.push_back({position[i], speed[i]});
    }

    sort(rank.rbegin(), rank.rend());

    stack<double> st;

    for (int i = 0; i < cars; i++)
    {
      double time = (double)(target - rank[i].first) / rank[i].second;

      if (st.empty() || time > st.top())
      {
        st.push(time);
      }
    }

    return st.size();
  }
};