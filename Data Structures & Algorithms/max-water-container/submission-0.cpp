class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int cap = INT_MIN;

        for(int i =0; i < n; i++){
            for(int j = i+1; j< n; j++){
                cap = max(cap, min(heights[i], heights[j])*(j-i));
            }
        }

        return cap;

    }
};
