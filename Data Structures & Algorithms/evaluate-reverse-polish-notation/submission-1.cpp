class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;
    for (auto x : tokens)
    {
      if (x != "+" && x != "-" && x != "*" && x != "/")
      {
        st.push(stoi(x));
      }
      else
      {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        if (x == "+")
        {
          st.push(first+second);
        }
        if (x == "*")
        {
          st.push(first*second);
        }
        if (x == "-")
        {
          st.push(second-first);
        }
        if (x == "/")
        {
          st.push(second/first);
        }
      }
    }

    return st.top();
  }
};