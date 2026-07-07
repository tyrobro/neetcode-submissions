class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        int n = gas.size();

        for(int i =0; i < n; i++){
            gasSum += gas[i];
            costSum += cost[i];
        }
        if(gasSum < costSum){
            return -1;
        }

        int total = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            total += (gas[i]-cost[i]);
            if(total < 0){
                total = 0;
                ans = i+1;
            }
        }

        return ans;
    }
};
