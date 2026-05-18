class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if (n == 0) {
            return 0;
        }
        
        vector<int> suffix(n);
        vector<int> prefix(n);
        
        int sufMax = height[n-1];
        int preMax = height[0];

        for(int i = 0; i < n; i++){
            preMax = max(preMax, height[i]);
            prefix[i] = preMax; 
        }
        
        for(int i = n-1; i >= 0; i--){
            sufMax = max(sufMax, height[i]);
            suffix[i] = sufMax;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (min(prefix[i], suffix[i]) - height[i]);
        }

        return ans;
    }
};