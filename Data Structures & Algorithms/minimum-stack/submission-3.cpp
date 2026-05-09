class MinStack
{
public:
  stack<int> st;
  stack<int> least;
  MinStack()
  {
  }

  void push(int val)
  {
    st.push(val);
    if (!least.empty())
    {
      least.push(min(val, least.top()));
    }
    else
    {
      least.push(val);
    }
  }

  void pop()
  {
    st.pop();
    least.pop();
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return least.top();
  }
};