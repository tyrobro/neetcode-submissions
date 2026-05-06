class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> set;

    for (int x : nums)
    {
      set.insert(x);
    }

    int count = 1;
    int ans = 0;

    for (int x : set)
    {
      int lower = x - 1;
      int upper = x + 1;
      while (set.count(lower))
      {
        count++;
        lower--;
      }
      while (set.count(upper))
      {
        count++;
        upper++;
      }
      ans = max(count, ans);
      count = 1;
    }

    return ans;
  }
};