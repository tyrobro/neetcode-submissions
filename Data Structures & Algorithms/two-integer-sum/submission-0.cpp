class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsize = nums.size();
        vector<int> answer;
        for(int i = 0; i < numsize; i++)
        {
            for(int j = i+1; j < numsize; j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                }
                else
                {
                    continue;
                }
            }
        }
        return answer;
    }
};
