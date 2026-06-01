class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row*col-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int currow = mid/col, curcol = mid%col;
            int curr = matrix[currow][curcol];

            if(curr < target){
                l = mid+1;
            } else if(curr > target){
                r = mid-1;
            } else {
                return true;
            }
        }

        return false;
    }
};
