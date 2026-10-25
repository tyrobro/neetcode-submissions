class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int maxCurr = -1;
        vector<int> ans;
        for(int i =n-1; i >= 0; i--){
            if(heights[i] > maxCurr){
                ans.push_back(i);
                maxCurr = max(heights[i], maxCurr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};