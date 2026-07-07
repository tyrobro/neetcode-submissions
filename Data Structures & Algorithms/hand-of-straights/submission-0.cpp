class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        unordered_map<int, int> count;
        if(n % groupSize != 0) {
            return false;
        }
        for(int num: hand){
            count[num]++;
        }

        for(int x: hand){
            int start = x;
            while(count[start - 1] > 0) start--;
            while(start <= x) {
                while(count[start] > 0){
                    for(int i = start; i < start + groupSize; i++){
                        if(count[i] == 0) return false;
                        count[i]--;
                    }
                }

                start++;
            }
        }

        return true;
        

    }
};
